/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to merge two BST.
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
void inorder(treenode* root,vector<int>& vec){
    if(root==NULL)
        return;
    inorder(root->left,vec);
    //cout<<root->data<<" ";
    vec.push_back(root->data);
    inorder(root->right,vec);
}
void mergevec(vector<int>& vecf,vector<int>& vec1,vector<int>& vec2){
    int i=0,j=0;
    while(i<=vec1.size()&&j<=vec2.size()){
        if(vec1[i]<vec2[j]){
            //cout<<" i: "<<i<<" j: "<<j<<" vecf[i]: "<<vec1[i];
            vecf.push_back(vec1[i]);
            i++;
        }
        else{
            //cout<<" i: "<<i<<" j: "<<j<<" vecf[i]: "<<vec2[i];
            vecf.push_back(vec2[j]);
            j++;
        }
    }
    if(i==vec1.size()){
        for(int p=j;p<vec2.size();p++){
            vecf.push_back(vec2[p]);
        }
    }
    else if(j==vec1.size()){
        for(int p=i;p<vec1.size();p++){
            vecf.push_back(vec1[p]);
        }
    }
}
treenode* sortedarray2bst(vector<int>& vecf,int start,int end){
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    treenode* root=newnode(vecf[mid]);
    root->left=sortedarray2bst(vecf,start,mid-1);
    root->right=sortedarray2bst(vecf,mid+1,end);
    return root;
}
treenode* merge2bst(treenode* root1,treenode* root2){
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vecf;
    inorder(root1,vec1);
    inorder(root2,vec2);
    mergevec(vecf,vec1,vec2);
    cout<<endl;
    treenode* root=sortedarray2bst(vecf,0,vecf.size()-1);
    return root;
}
void inorder1(treenode* root){
    if(root==NULL)
        return;
    inorder1(root->left);
    cout<<root->data<<" ";
    inorder1(root->right);
}
int main(){
    string str;
    string str1;
    getline(cin,str);
    getline(cin,str1);
    istringstream ss(str);
    int p;
    vector<int> vec1;
    while(ss>>p){
        vec1.push_back(p);
    }
    treenode* root1=NULL;
    root1=insert(root1,vec1[0]);
    for(int i=1;i<vec1.size();i++){
        insert(root1,vec1[i]);
    }
    istringstream stream(str1);
    int q;
    vector<int> vec2;
    while(stream>>q){
        vec2.push_back(q);
    }
    treenode* root2=NULL;
    root2=insert(root2,vec2[0]);
    for(int i=1;i<vec2.size();i++){
        insert(root2,vec2[i]);
    }
    cout<<endl;
    cout<<" inorder of tree1: ";
    inorder1(root1);
    cout<<endl;
    cout<<" inorder of tree2: ";
    inorder1(root2);
    cout<<endl;
    treenode* rootf=merge2bst(root1,root2);
    cout<<"inorder of final merged tree:"<<endl;
    inorder1(rootf);
    cout<<endl;
    return 0;
}
