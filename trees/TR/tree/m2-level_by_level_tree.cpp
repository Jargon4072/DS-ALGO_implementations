/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|________________________________________________________|
*/
//using 1 queue and a counting its size.
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
  queue<node*> q;
  node* current=new node;
  q.push(root);
  //q.push(NULL);
  while(1){
  int count=q.size();
  if(!count)
    break;
  while(count>0){
    current=q.front();
    q.pop();
    cout<<current->data<<" ";
    if(current->left)
      q.push(current->left);
    if(current->right)
      q.push(current->right);
    //if(q.front()==NULL){
      //q.pop();
      //q.push(NULL);
      //cout<<endl;
      count--;
    }
    cout<<endl;
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