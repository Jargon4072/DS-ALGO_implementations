#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int data;
    treenode* left;
    treenode* right;
};
treenode* newnode(int value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=new_node->right=NULL;
    return new_node;
}
void inorder(treenode* root,int hd,map<int,vector<int>> &m){
    if(root==NULL)
        return;
    m[hd].push_back(root->data);
    inorder(root->left,hd-1,m);
    inorder(root->right,hd+1,m);
}
void print_tree_vt(treenode* root){
    map<int,vector<int>> m;
    int hd=0;
    inorder(root,hd,m);
    map<int,vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();++i){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);

    cout << "Vertical order traversal is:\n";
    print_tree_vt(root);
    return 0;
}
