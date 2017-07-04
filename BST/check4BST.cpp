/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to check if a given tree is binary or not.
#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
treenode* newnode(int value){
    treenode* temp=new treenode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
treenode* insert(treenode* root,int value){
    if(root==NULL){
        root=newnode(value);
        return root;
    }
    if(value>root->data){
        root->right=insert(root->right,value);
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
    }
    return root;
}
void inorder(treenode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    //cout<<root->data<<" ";
    vec.push_back(root->data);
    inorder(root->right);
}
int main(){
    treenode *root    = newnode(4);
    root->left        = newnode(2);
    root->right       = newnode(5);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    inorder(root);
    if(is_sorted(vec.begin(),vec.end())){
        cout<<endl<<"Given tree is BST."<<endl;
    }
    else{
        cout<<endl<<"Given tree is not a BST."<<endl;
    }
}
