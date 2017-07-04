/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to print levelorder traversal line by line(i.e. level wise).
#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
void levelorderlinebyline(treenode* root){     //TODO: implement it with count=q.size();
    if(root==NULL)
        return;
    treenode* temp=new treenode;
    temp=root;
    queue<treenode *> q;
    int count=0;
    int t=0;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        if(count==0&&temp->left!=NULL&&temp->right!=NULL){
            t=2;
            cout<<endl;
        }
        else if(count==0&&((temp->left!=NULL&&temp->right==NULL)||(temp->left==NULL&&temp->right!=NULL))){
            t=1;
            cout<<endl;
        }

        if(t==0){
            cout<<endl;
            t=count;
            count=0;
        }
        q.push(temp->left);
        q.push(temp->right);
        treenode* p=q.front();
        q.pop();
        t--;
        temp=p;
        if(temp->left!=NULL&&temp->right!=NULL){
            count+=2;
        }
        else if((temp->left!=NULL&&temp->right==NULL)||(temp->left==NULL&&temp->right!=NULL)){
            count+=1;
        }
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
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<"Level order tree traversal is: "<<endl;
    levelorderlinebyline(root);
    cout<<endl;
    return 0;
}
