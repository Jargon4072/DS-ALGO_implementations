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
/*int height(treenode* root){        //modification of levelorder traversal line by line.
    stack<treenode* > st;
    int count1=0;
    if(root==NULL)
        return 0;
    st.push(root);
    while(1){
        int count=st.size();
        if(count==0){
            break;
        }
        else{
            while(count>0){
                treenode* new_node=new treenode;
                new_node=st.top();
                st.pop();
                if(new_node->left!=NULL){
                    st.push(new_node->left);
                }
                if(new_node->right!=NULL){
                    st.push(new_node->right);
                }
                count--;
            }
            count1++;
        }
    }
    return count1;
}*/
int height(treenode* root){       //simple and elegent method. power of recursion :)
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(lheight>rheight)
        return lheight+1;
    else
        return rheight+1;
}
int main(){
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<"height of tree is: ";
    cout<<height(root)<<endl;
    return 0;
}
