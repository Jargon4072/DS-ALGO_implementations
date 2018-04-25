# Imports
import tensorflow as tf
import tensorflow.contrib.slim as slim  # TensorFlow-Slim
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from PIL import Image
from sklearn.cross_validation import train_test_split
import numpy as np
import cv2
import math
import os
import time
import pickle
# %matplotlib inline
IMG_SIZE = 32  # square image of size IMG_SIZE x IMG_SIZE
GRAYSCALE = False  # convert image to grayscale?
NUM_CHANNELS = 1 if GRAYSCALE else 3
NUM_CLASSES = 43

# Model parameters
LR = 5e-3  # learning rate
KEEP_PROB = 0.5  # dropout keep probability
OPT = tf.train.GradientDescentOptimizer(learning_rate=LR)  # choose which optimizer to use

# Training process
RESTORE = False  # restore previous model, don't train?
RESUME = False  # resume training from previously trained model?
NUM_EPOCH = 40
BATCH_SIZE = 128  # batch size for training (relatively small)
BATCH_SIZE_INF = 2048  # batch size for running inference, e.g. calculating accuracy
VALIDATION_SIZE = 0.2  # fraction of total training set to use as validation set
SAVE_MODEL = True  # save trained model to disk?
MODEL_SAVE_PATH = 'model.ckpt'  # where to save trained model

image_files  = ['sample_images/' + image_file for image_file in os.listdir('sample_images')]
images = []
def rgb_to_gray(images):
    """
    Convert batch of RGB images to grayscale
    Use simple average of R, G, B values, not weighted average

    Arguments:
        * Batch of RGB images, tensor of shape (batch_size, 32, 32, 3)

    Returns:
        * Batch of grayscale images, tensor of shape (batch_size, 32, 32, 1)
    """
    images_gray = np.average(images, axis=3)
    images_gray = np.expand_dims(images_gray, axis=3)
    return images_gray


def preprocess_data(X, y):
    """
    Preprocess image data, and convert labels into one-hot

    Arguments:
        * X: Image data
        * y: Labels

    Returns:
        * Preprocessed X, one-hot version of y
    """
    # Convert from RGB to grayscale if applicable
    if GRAYSCALE:
        X = rgb_to_gray(X)

    # Make all image array values fall within the range -1 to 1
    # Note all values in original images are between 0 and 255, as uint8
    X = X.astype('float32')
    X = (X - 128.) / 128.

    # Convert the labels from numerical labels to one-hot encoded labels
    y_onehot = np.zeros((y.shape[0], NUM_CLASSES))
    for i, onehot_label in enumerate(y_onehot):
        onehot_label[y[i]] = 1.
    y = y_onehot

    return X, y


def next_batch(X, y, batch_size, augment_data):
    """
    Generator to generate data and labels
    Each batch yielded is unique, until all data is exhausted
    If all data is exhausted, the next call to this generator will throw a Stop Iteration

    Arguments:
        * X: image data, a tensor of shape (dataset_size, 32, 32, 3)
        * y: labels, a tensor of shape (dataset_size,)  <-- i.e. a list
        * batch_size: Size of the batch to yield
        * augment_data: Boolean value, whether to augment the data (i.e. perform image transform)

    Yields:
        A tuple of (images, labels), where:
            * images is a tensor of shape (batch_size, 32, 32, 3)
            * labels is a tensor of shape (batch_size,)
    """
    # A generator in this case is likely overkill,
    # but using a generator is a more scalable practice,
    # since future datasets may be too large to fit in memory

    # We know X and y are randomized from the train/validation split already,
    # so just sequentially yield the batches
    start_idx = 0
    while start_idx < X.shape[0]:
        images = X[start_idx : start_idx + batch_size]
        labels = y[start_idx : start_idx + batch_size]

        yield (np.array(images), np.array(labels))

        start_idx += batch_size


def calculate_accuracy(data_gen, data_size, batch_size, accuracy, x, y, keep_prob, sess):
    """
    Helper function to calculate accuracy on a particular dataset

    Arguments:
        * data_gen: Generator to generate batches of data
        * data_size: Total size of the data set, must be consistent with generator
        * batch_size: Batch size, must be consistent with generator
        * accuracy, x, y, keep_prob: Tensor objects in the neural network
        * sess: TensorFlow session object containing the neural network graph

    Returns:
        * Float representing accuracy on the data set
    """
    num_batches = math.ceil(data_size / batch_size)
    last_batch_size = data_size % batch_size

    accs = []  # accuracy for each batch

    for _ in range(num_batches):
        images, labels = next(data_gen)

        # Perform forward pass and calculate accuracy
        # Note we set keep_prob to 1.0, since we are performing inference
        acc = sess.run(accuracy, feed_dict={x: images, y: labels, keep_prob: 1.})
        accs.append(acc)

    # Calculate average accuracy of all full batches (the last batch is the only partial batch)
    acc_full = np.mean(accs[:-1])

    # Calculate weighted average of accuracy accross batches
    acc = (acc_full * (data_size - last_batch_size) + accs[-1] * last_batch_size) / data_size

    return acc
def neural_network():
    """
    Define neural network architecture
    Return relevant tensor references
    """
    with tf.variable_scope('neural_network'):
        # Tensors representing input images and labels
        x = tf.placeholder('float', [None, IMG_SIZE, IMG_SIZE, NUM_CHANNELS])
        y = tf.placeholder('float', [None, NUM_CLASSES])

        # Placeholder for dropout keep probability
        keep_prob = tf.placeholder(tf.float32)

        # Neural network architecture: Convolutional Neural Network (CNN)
        # Using TensorFlow-Slim to build the network:
        # https://github.com/tensorflow/tensorflow/tree/master/tensorflow/contrib/slim

        # Use batch normalization for all convolution layers
        with slim.arg_scope([slim.conv2d], normalizer_fn=slim.batch_norm):
            # Given x shape is (32, 32, 3)
            # Conv and pool layers
            net = slim.conv2d(x, 16, [3, 3], scope='conv0')  # output shape: (32, 32, 16)
            net = slim.max_pool2d(net, [3, 3], 1, padding='SAME', scope='pool0')  # output shape: (32, 32, 16)
            net = slim.conv2d(net, 64, [5, 5], 3, padding='VALID', scope='conv1')  # output shape: (10, 10, 64)
            net = slim.max_pool2d(net, [3, 3], 1, scope='pool1')  # output shape: (8, 8, 64)
            net = slim.conv2d(net, 128, [3, 3], scope='conv2')  # output shape: (8, 8, 128)
            net = slim.conv2d(net, 64, [3, 3], scope='conv3')  # output shape: (8, 8, 64)
            net = slim.max_pool2d(net, [3, 3], 1, scope='pool3')  # output shape: (6, 6, 64)

            # Final fully-connected layers
            net = tf.contrib.layers.flatten(net)
            net = slim.fully_connected(net, 1024, scope='fc4')
            net = tf.nn.dropout(net, keep_prob)
            net = slim.fully_connected(net, 1024, scope='fc5')
            net = tf.nn.dropout(net, keep_prob)
            net = slim.fully_connected(net, NUM_CLASSES, scope='fc6')

        # Final output (logits)
        logits = net

        # Loss (data loss and regularization loss) and optimizer
        loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits, y))
        optimizer = OPT.minimize(loss)

        # Prediction (used during inference)
        predictions = tf.argmax(logits, 1)

        # Accuracy metric calculation
        correct_prediction = tf.equal(predictions, tf.argmax(y, 1))
        accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

    # Return relevant tensor references
    return x, y, keep_prob, logits, optimizer, predictions, accuracy


for image_file in image_files:
    image = Image.open(image_file)
    image = image.convert('RGB')
    image = image.resize((IMG_SIZE, IMG_SIZE), Image.ANTIALIAS)
    image = np.array(list(image.getdata()), dtype='uint8')
    image = np.reshape(image, (32, 32, 3))
    images.append(image)
images = np.array(images, dtype='uint8')

for i, image in enumerate(images):
    plt.subplot(3, 3, i+1)
    plt.imshow(image)
    plt.title(image_files[i])

plt.tight_layout()
plt.show()

label_map = {}
with open('signnames.csv', 'r') as f:
    first_line = True
    for line in f:
        # Ignore first line
        if first_line:
            first_line = False
            continue

        # Populate label_map
        label_int, label_string = line.split(',')
        label_int = int(label_int)

        label_map[label_int] = label_string

        # Pre-process the image (don't care about label, put dummy labels)

images, _ = preprocess_data(images, np.array([0 for _ in range(images.shape[0])]))

with tf.Graph().as_default(), tf.Session() as sess:
    # Instantiate the CNN model
    x, y, keep_prob, logits, optimizer, predictions, accuracy = neural_network()

    # Load trained weights
    saver = tf.train.Saver()
    saver.restore(sess, MODEL_SAVE_PATH)

    # Run inference on CNN to make predictions, and remember the logits for later
    lgts, preds = sess.run([logits, predictions], feed_dict={x: images, keep_prob: 1.})

final_preds = [label_map[pred] for pred in preds]


print('Predictions on sample images\n')
for i in range(images.shape[0]):
    print('%s --> %s' % (image_files[i], final_preds[i]))
