//
// Created by krishna_warrior on 1/3/18.
//

// using 2 queues. 
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
void LevelByLevel(node* root){
  if(root==NULL)
    return;
  queue<node*> q1;
  queue<node*> q2;
  node* current=new node;
  q1.push(root);
  while(!q1.empty()|| !q2.empty()){
    if(!q1.empty()&&q2.empty()){
      while(!q1.empty()){
      current=q1.front();
      q1.pop();
      cout<<current->data<<" ";
      if(current->left)
        q2.push(current->left);
      if(current->right)
        q2.push(current->right);
    }
    if(q1.empty())
      cout<<endl;
    }
    if(q1.empty() && !q2.empty()){
      while(!q2.empty()){
        current=q2.front();
        q2.pop();
        if(current->left)
          q1.push(current->left);
        if(current->right)
          q1.push(current->right);
        cout<<current->data<<" ";
      }
      if(q2.empty())
        cout<<endl;
    }
  }
}
int main(){
  // TREE T
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    node *T        = newnode(26);
    T->right              = newnode(3);
    T->right->right       = newnode(3);
    T->left               = newnode(10);
    T->left->left         = newnode(4);
    T->left->left->right  = newnode(30);
    T->left->right        = newnode(6);
    LevelByLevel(T);
    return 0;
}