/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to print leveloreder traversal of tree using queue.
#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
void levelorderqueue(treenode* root){
    if(root==NULL)
        return;
    treenode* temp=new treenode;
    temp=root;
    queue<treenode *> q;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        q.push(temp->left);
        q.push(temp->right);
        treenode* p=q.front();
        q.pop();
        temp=p;
    }
}
treenode* newnode(int value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
int main(){
    treenode* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    cout<<"Level order tree traversal is: ";
    levelorderqueue(root);
    cout<<endl;
    return 0;
}
