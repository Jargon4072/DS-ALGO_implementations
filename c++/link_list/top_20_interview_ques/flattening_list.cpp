/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-04-22T11:22:58+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-04-22T12:36:57+05:30
  program to flatten a linked list of form:
          5 -> 10 -> 19 -> 28
          |    |     |     |
          V    V     V     V
          7    20    22    35
          |          |     |
          V          V     V
          8          50    40
          |                |
          V                V
          30               45
 */

 #include <stdio.h>
 #include <stdlib.h>

 // A Linked List Node
 typedef struct Node
 {
     int data;
     struct Node *right;
     struct Node *down;
 } Node;

/* complete this function */
Node* flatten_list(Node* root){ //TODO: complete this ASAP
  /* Write your code here*/
  
}


/*-------------------------- Pre coded funtions ----------------------------------- */
 void push (Node** head_ref, int new_data)
 {
     /* allocate node */
     Node* new_node = (Node *) malloc(sizeof(Node));
     new_node->right = NULL;

     /* put in the data  */
     new_node->data  = new_data;

     /* link the old list off the new node */
     new_node->down = (*head_ref);

     /* move the head to point to the new node */
     (*head_ref)    = new_node;
 }

 /* Function to print nodes in the flattened linked list */
 void printList(Node *node)
 {
     while (node != NULL)
     {
         printf("%d ", node->data);
         node = node->down;
     }
 }

 int main()
 {
     Node* root = NULL;

     /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
     */
     push( &root, 30 );
     push( &root, 8 );
     push( &root, 7 );
     push( &root, 5 );

     push( &( root->right ), 20 );
     push( &( root->right ), 10 );

     push( &( root->right->right ), 50 );
     push( &( root->right->right ), 22 );
     push( &( root->right->right ), 19 );

     push( &( root->right->right->right ), 45 );
     push( &( root->right->right->right ), 40 );
     push( &( root->right->right->right ), 35 );
     push( &( root->right->right->right ), 20 );

     root=flatten_list(root);
     printList(root);
   return 0;
 }