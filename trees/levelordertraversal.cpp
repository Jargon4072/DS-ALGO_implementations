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
int height(treenode* root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(lheight>rheight)
        return(lheight+1);
    else
        return(rheight+1);
}
void printgivenlevel(treenode* root,int level){
    treenode* temp=new treenode;
    temp=root;
    if(root==NULL)
        return;
    else if(level==1)
        cout<<temp->data<<" ";
    else{
        printgivenlevel(temp->left,level-1);
        printgivenlevel(temp->right,level-1);
    }
}
void levelorder(treenode* root){
    for(int i=1;i<=height(root);i++){
        printgivenlevel(root,i);
    }
}
int main(){
    treenode* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    cout<<"Level order tree traversal is: ";
    levelorder(root);
    cout<<endl;
    return 0;
}
