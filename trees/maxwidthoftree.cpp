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
int maxwidth(treenode* root){     //TODO: implement it with preorder traversal.
    if(root==NULL)
        return 0;
    queue<treenode* > q;
    q.push(root);
    int w=0;
    while(1){
        int count=q.size();
        w=max(w,count);
        if(count==0)
            break;
        while(count>0){
            treenode* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            count--;
        }
    }
    return w;
}
int main(){
  treenode* root    =newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->right->right = newnode(8);
  root->right->right->left  = newnode(6);
  root->right->right->right  = newnode(7);
  cout<<" max. width is: ";
  cout<<maxwidth(root)<<endl;
}
