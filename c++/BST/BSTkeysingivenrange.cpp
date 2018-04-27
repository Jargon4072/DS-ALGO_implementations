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

void printkeyinrange(treenode* root,int k1,int k2){
    if(root==NULL)
        return;
    if(k1<root->data){
        printkeyinrange(root->left,k1,k2);
    }
    if(k1<=root->data&&k2>=root->data){
        cout<<root->data<<" ";
    }
    if(k2>root->data){
        printkeyinrange(root->right,k1,k2);
    }
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
        //cout<<vec1[i]<<" ";
    }
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    cout<<"Keys in range "<<n1<<" to "<<n2<<" are: ";
    printkeyinrange(root,n1,n2);
    cout<<endl;
    return 0;
}
