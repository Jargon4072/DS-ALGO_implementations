//
// Created by krishna_warrior on 2/12/17.
//
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* newnode(int data){
    node* new_node=new node;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void leveloreder(node* root){
    node* temp=new node;
    temp=NULL;
    queue<node* > q;
    if(root==NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}
int main(){
    node* root=new node;
    root=NULL;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    leveloreder(root);
    return 0;
}
