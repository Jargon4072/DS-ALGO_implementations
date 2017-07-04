#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
int size(treenode* root){
    if(root==NULL){
        return 0;
    }
    else
        return (size(root->left)+1+size(root->right));
}
treenode* newnode(int value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
int main(){
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<"size of tree is: ";
    cout<<size(root)<<endl;
    return 0;
}
