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
int main(){
    string str;

    getline(cin,str);
    istringstream stream(str);
    int p;
    vector<int> vec;
    while(stream>>p){
        vec.push_back(p);
    }
    treenode* root=NULL;
    root=insert(root,vec[0]);
    for(int i=1;i<vec.size();i++){
        insert(root,vec[i]);
        //cout<<vec[i]<<" ";
    }
    cout<<"inorder traversal is: "<<endl;
    inorder(root);
    return 0;
}
