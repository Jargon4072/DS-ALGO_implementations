
//without using hashing;
#include<bits/stdc++.h>
using namespace std;
int array[1000005]={0};
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
void findMinMax(treenode* root,int *min,int *max,int hd){
    if(root==NULL){
        return;
    }
    if(hd<*min){
        *min=hd;
    }
    else if(hd>*max){
        *max=hd;
    }
    findMinMax(root->left,min,max,hd-1);
    findMinMax(root->right,min,max,hd+1);
}
void printVerticalTree(treenode* root,int line_no,int hd){
    if(root==NULL){
        return;
    }
    if(hd==line_no){
        cout<<root->data<<" ";
    }
    printVerticalTree(root->left,line_no,hd-1);
    printVerticalTree(root->right,line_no,hd+1);
}
void print_tree_vt(treenode* root){
    int min=0;
    int max=0;
    findMinMax(root,&min,&max,0);
    for(int i=min;i<=max;i++){
        printVerticalTree(root,i,0);
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
