#include<bits/stdc++.h>
using namespace std;
struct treenode{
    char data;
    treenode* left;
    treenode* right;
};
treenode* newnode(char value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
int search(char arr[], int strt, int end, char value){
    int i;
    for(i = strt; i <= end; i++){
    if(arr[i] == value)
        return i;
    }
}
treenode* buildTree(char in[], char pre[], int inStrt, int inEnd){    //TODO: implement it again.aldo do for in & post https://github.com/Jargon4072/DS-ALGO_implementations/issues/10 id:9
  static int preIndex = 0;

  if(inStrt > inEnd)
        return NULL;
  treenode *tNode = newnode(pre[preIndex++]);
  if(inStrt == inEnd)
        return tNode;
  int inIndex = search(in, inStrt, inEnd, tNode->data);
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
  return tNode;
}
void inorder(treenode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in)/sizeof(in[0]);
    treenode* root;
    cout<<"Inoreder traversal of final tree is: ";
    root=buildTree(in,pre,0,len-1);
    inorder(root);
}
