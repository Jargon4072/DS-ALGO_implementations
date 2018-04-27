/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//non-recursive solution of inorder traversal.
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
void nonrecursiveinorder(treenode* root){    //TODO: implement it wihtout stack. https://github.com/Jargon4072/DS-ALGO_implementations/issues/3 id:2
    stack<treenode* > st;
    treenode* temp=new treenode;
    temp=root;
    while(1){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        if(st.empty())
            break;
        temp=st.top();    //temp must be reset to st.top() as above while loop sets it to leaf node.
        st.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
int main(){
    treenode *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<"inorder tree traversal is: ";
    nonrecursiveinorder(root);
    cout<<endl;
    return 0;
}
