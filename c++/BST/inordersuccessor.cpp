/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//inorder successor of a given BST.
#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
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
        root=newnode(value);
        return root;
    }
    if(value>root->data){
        root->right=insert(root->right,value);
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
    }
    return root;
}
void inorder(treenode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    //cout<<root->data<<" ";
    vec.push_back(root->data);
    inorder(root->right);
}
int main(){
    string str;

    getline(cin,str);
    istringstream stream(str);
    int p;
    vector<int> vec1;
    while(stream>>p){
        vec1.push_back(p);
    }
    treenode* root=NULL;
    root=insert(root,vec1[0]);
    for(int i=1;i<vec1.size();i++){
        insert(root,vec1[i]);
        //cout<<vec[i]<<" ";
    }
    int value;
    cin>>value;
    cout<<"inorder Successor is: ";
    inorder(root);
    for(int i=0;i<vec.size();i++){
        if(vec[i]==value){
            cout<<vec[i+1]<<endl;
            break;
        }
        if(vec[i]<value&&vec[i+1]>value){
            cout<<vec[i+1]<<endl;
            break;
        }
    }
    return 0;
}
