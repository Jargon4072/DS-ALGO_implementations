#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
treenode* newnode(int value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
treenode* insert(treenode* root,int value){
    if(root==NULL){
        root=newnode(value);
        return root;
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}
void correctBSTutil(treenode* root,treenode** first,
    treenode** middle,treenode** last,treenode** prev){
        if(root){
            correctBSTutil(root->left,first,middle,last,prev);
            if(*prev && root->data<(*prev)->data){
                if(!*first){
                    *first=*prev;
                    *middle=root;
                }
                else *last=root;
            }
            *prev=root;
            correctBSTutil(root->right,first,middle,last,prev);
        }
    }
void correctBST(treenode* root){
    treenode *first,*middle,*last,*prev;
    first=middle=last=prev=NULL;
    correctBSTutil(root,&first,&middle,&last,&prev);
    if(first && last)
        swap(&(first->data),&(last->data));
    else if(first && middle){
        swap(&(first->data),&(middle->data));
    }
}
void inorder(treenode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    treenode *root = newnode(6);
    root->left        = newnode(10);
    root->right       = newnode(2);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(12);
    root->right->left = newnode(7);
    cout<<"original tree: ";
    inorder(root);
    cout<<endl;
    correctBST(root);
    cout<<"Corrected tree: ";
    inorder(root);
    cout<<endl;
    return 0;
}
