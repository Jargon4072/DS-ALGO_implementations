//program to determine a given tree is subtree of other or not.

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
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void inorder(treenode* root,vector<int>& vec){
    if(root==NULL)
        return;
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}
void preorder(treenode* root,vector<int>& vec){
    if(root==NULL)
        return;
    vec.push_back(root->data);
    preorder(root->left,vec);
    preorder(root->right,vec);
}
bool issubarray(vector<int>& vec1,vector<int>& vec2){
    char arr1[1000005];
    char arr2[1000005];
    for(int i=0;i<vec1.size();i++){
        arr1[i]=vec1[i]+'0';
    }
    for(int i=0;i<vec2.size();i++){
        arr2[i]=vec2[i]+'0';
    }
    return (strstr(arr1,arr2)!=NULL);
}
int main(){
    vector<int> vecin;
    vector<int> vecpre;
    vector<int> subin;
    vector<int> subpre;

    // TREE T
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    treenode *T        = newnode(26);
    T->right              = newnode(3);
    T->right->right       = newnode(3);
    T->left               = newnode(10);
    T->left->left         = newnode(4);
    T->left->left->right  = newnode(30);
    T->left->right        = newnode(6);

    // TREE S
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    treenode *S    = newnode(10);
    S->right          = newnode(6);
    S->left           = newnode(4);
    S->left->right    = newnode(30);

    inorder(T,vecin);
    preorder(T,vecpre);

    inorder(S,subin);
    preorder(S,subpre);
    if(issubarray(vecin,subin)&&issubarray(vecpre,subpre)){
        cout<<"Tree S is subtree of T."<<endl;
    }
    else
        cout<<"Tree S is not a subtree of T."<<endl;
    return 0;
}
