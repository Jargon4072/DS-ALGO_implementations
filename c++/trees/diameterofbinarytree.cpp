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
/*int height(treenode* root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    return ((lheight>rheight)?(lheight+1):(rheight+1));
}
int diameter(treenode* root){     //basic func. O(2^n).
    if(root==NULL){
        return 0;
    }
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        return max(lheight+1+rheight,max(diameter(root->left),diameter(root->right)));
    }
}*/
int diameter(treenode* root,int *height){    //optimized fun, O(n).
    if(root==NULL){
        *height=0;                      //TODO: try to implement it without pointer https://github.com/Jargon4072/DS-ALGO_implementations/issues/12 id:11
        return 0;                               //i.e. with int height insted of int* height
    }
    int lh=0,rh=0;
    int ldiameter=diameter(root->left,&lh);
    int rdiameter=diameter(root->right,&rh);
    *height=max(lh,rh)+1;
    return max(lh+rh+1,max(ldiameter,rdiameter));
}
int main(){
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    int height=0;
    cout<<" diameter is: ";
    cout<<diameter(root,&height)<<endl;
    return 0;
}
