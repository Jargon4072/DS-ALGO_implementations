/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to find lowest common ancestor of two given nodes.
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
treenode* lca(treenode* root, int n1, int n2){
    if(root==NULL){
        cout<<"Empty tree."<<endl;
        return NULL;
    }

    if(n1<root->data&&n2<root->data){
        root=lca(root->left,n1,n2);
    }
    else if(n1>root->data&&n2>root->data){
        root=lca(root->right,n1,n2);
    }
    else{
        cout<<root->data<<endl;
    }
    return root;
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
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    cout<<"Lowest common ancestor of "<<n1<<" & "<<n2<<" is: ";
    treenode* temp=lca(root,n1,n2);
    return 0;
}
