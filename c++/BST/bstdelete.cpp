#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
treenode* newnode(int value){
    treenode* temp=new treenode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
treenode* insert(treenode* root,int value){
    if(root==NULL){
        return newnode(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(treenode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
treenode* minval(treenode* root){
    if(root==NULL){
        return root;
    }
    treenode* new_node;
    new_node=root;
    while(new_node->left!=NULL){
        new_node=new_node->left;
    }
    return new_node;
}
treenode* deletetreenode(treenode* root,int value){
    if(root==NULL){
        return root;
    }
    else if(value<root->data){
        root->left=deletetreenode(root->left,value);
    }
    else if(value>root->data){
        root->right=deletetreenode(root->right,value);
    }
    else{
        //one child
        if(root->left==NULL){
            treenode* temp=new treenode;
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            treenode* temp=new treenode;
            temp=root->left;
            free(root);
            return temp;
        }
        //no child
        if(root->left==NULL&&root->right==NULL){
           free(root);
        }
        //two child
        treenode* new_node;
        new_node=minval(root->right);
        root->data=new_node->data;
        root->right=deletetreenode(root->right,new_node->data);
    }
    return root;
}
int main(){
    treenode* root=new treenode;
    root=NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout<<"Tree is: ";
    inorder(root);
    cout<<endl<<"enter nodes to delete: ";
    string str;
    getline(cin,str);
    istringstream stream(str);
    int p;
    vector<int> vec;
    while(stream>>p){
        vec.push_back(p);
    }
    for(int i=0;i<vec.size();i++){
        cout<<endl<<"deleting "<<vec[i]<<" from Tree....."<<endl;
        cout<<"Tree after deleting "<<endl;
        root=deletetreenode(root,vec[i]);
        inorder(root);
    }
    return 0;
}
