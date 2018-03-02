//
// Created by krishna_warrior on 6/1/18.
//

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
int search(int arr[],int start,int end,int data){
    int i;
    for( i=start;i<=end;i++){
        if(arr[i]==data)
            return i;
    }
}
node* buildtree(int in[],int pre[], int instart,int inend){
    static int index=0;
    if(instart>inend)
        return NULL;
    node* root=newnode(pre[index]);
    index++;
    if(instart==inend)
        return root;
    int inindex=search(in,instart,inend,root->data);
    root->left=buildtree(in,pre,instart,inindex-1);
    root->right=buildtree(in,pre,inindex+1,inend);
    return root;
}
void postorder(node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int in[]={4,2,5,1,6,3,7};
    int pre[]={1,2,4,5,3,6,7};
    int size=sizeof(in)/sizeof(in[0]);
    node* root=buildtree(in,pre,0,size-1);
    postorder(root);
    cout<<endl;
    return 0;
}