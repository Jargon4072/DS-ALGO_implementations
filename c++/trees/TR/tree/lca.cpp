//
// Created by krishna_warrior on 6/1/18.
//
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* newnode(int value){
    node* new_node=new node;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

node* lca(node* root, node* a, node* b){
    node* left=new node;
    node* right=new node;
    if(root==NULL)
        return root;
    if(root==a||root==b)
        return root;

    left=lca(root->left,a,b);
    right=lca(root->right,a,b);
    if(left&&right)
        return root;
    else
        return (left?left:right);
}

int main() {
    node *root = newnode(20);
    root->left = newnode(8);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    root->right = newnode(22);
    root->right->right = newnode(25);
    node* temp=lca(root,root->left->right,root->right->right);
    cout<<temp->data<<endl;

    return 0;
}