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
void preorder(treenode* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
treenode* array2bst(vector<int> & vec,int start,int end){
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    treenode* root=newnode(vec[mid]);
    root->left=array2bst(vec,start,mid-1);
    root->right=array2bst(vec,mid+1,end);
    return root;
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
    treenode* root=array2bst(vec1,0,vec1.size()-1);
    preorder(root);
    return 0;
}
