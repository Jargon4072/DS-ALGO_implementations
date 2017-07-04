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
void inorder_pred(treenode* root, treenode* &pre, treenode* &suc, int value){
    if(root==NULL){
        return;
    }
    if(root->data==value){
        if(root->left!=NULL){
            treenode* temp=root->left;
            while(temp->right)
                temp=temp->right;
            pre=temp;
        }
        if(root->right!=NULL){
            treenode* temp=root->right;
            while(temp->left)
                temp=temp->left;
            suc=temp;
        }
        return;
    }
    if(root->data>value){
        suc=root;
        inorder_pred(root->left,pre,suc,value);
    }
    else{
        pre=root;
        inorder_pred(root->right,pre,suc,value);
    }
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
    int value;
    cin>>value;
    treenode* pre=NULL;
    treenode* suc=NULL;
    inorder_pred(root,pre,suc,value);
    if (pre != NULL)
    cout << "Predecessor is: " << pre->data << endl;
    else
    cout << "No Predecessor";

    if (suc != NULL)
    cout << "Successor is: " << suc->data;
    else
    cout << "No Successor";
    return 0;
}
