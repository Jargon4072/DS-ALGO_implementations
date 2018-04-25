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
void print_leaf(treenode* root){
    if(root==NULL)
        return;
    print_leaf(root->left);
    if(root->left==NULL&&root->right==NULL)
        cout<<root->data<<" ";
    print_leaf(root->right);
}
void print_boundry_left(treenode* root){
    if(root==NULL)
        return;
    if(root->left){
        cout<<root->data<<" ";
        print_boundry_left(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        print_boundry_left(root->right);
    }
}
void print_boundry_right(treenode* root){
    if(root==NULL){
        return;
    }
    if(root->right){
        print_boundry_right(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        print_boundry_right(root->left);
        cout<<root->data<<" ";
    }
}
void print_boundary_traveral(treenode* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_boundry_left(root->left);
    print_leaf(root->left);
    print_leaf(root->right);
    print_boundry_right(root->right);
}
int main(){
    treenode* root         = newnode(20);
    root->left                = newnode(8);
    root->left->left          = newnode(4);
    root->left->right         = newnode(12);
    root->left->right->left   = newnode(10);
    root->left->right->right  = newnode(14);
    root->right               = newnode(22);
    root->right->right        = newnode(25);
    print_boundary_traveral(root);
    return 0;

}
