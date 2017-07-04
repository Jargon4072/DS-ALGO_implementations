#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
treenode* newnode(int value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void mirrortree(treenode* root){
    if(root==NULL)
        return;
    treenode* temp=new treenode;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrortree(root->left);
    mirrortree(root->right);
}
void printLevelOrder(treenode *root)       //you should use inorder traversal here, levelorder is used here for
{                                          //better visibality of tree.
    if (root == NULL)  return;
    queue<treenode *> q;
    q.push(root);
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
        while (nodeCount > 0)
        {
            treenode *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}
int main(){
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<"the original tree is: "<<endl;
    printLevelOrder(root);
    cout<<endl<<" mirror tree is: "<<endl;
    mirrortree(root);
    printLevelOrder(root);
    return 0;
}
