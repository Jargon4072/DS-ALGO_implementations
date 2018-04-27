/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Build a dream                                        |
|          and dream will build you.'                    |
|________________________________________________________|
*/
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
void spiral_level(node* root){
  if(root==NULL)
    return;
  queue<node*> q;
  stack<node*> st;
  int count=0;
  int level=1;
  q.push(root);
  while(!q.empty()){
    if(level%2){
    count=q.size();
    while(count--){
      root=q.front();
      q.pop();
      st.push(root);
      if(root->left)
        q.push(root->left);
      if(root->right)
        q.push(root->right);
      }
    }
    else{
      count=q.size();
      while(count--){
        root=q.front();
        q.pop();
        st.push(root);
        if(root->right)
          q.push(root->right);
        if(root->left)
          q.push(root->left);
        }
    }
    level++;

  }
  while(!st.empty()){
    cout<<st.top()->data<<" ";
    st.pop();
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
    spiral_level(T);
    return 0;
}