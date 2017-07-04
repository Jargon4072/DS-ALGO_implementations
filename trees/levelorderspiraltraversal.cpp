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
void spirallevelorder(treenode* root){
    if (root == NULL)  return;
    queue<treenode *> q;
    stack<int> st;
    int level=0;
    q.push(root);
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
        while (nodeCount > 0)
        {
            treenode *node = q.front();
            if(level%2==0){
                st.push(node->data);
            }
            else{
                cout << node->data << " ";
            }
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        if(level%2==0){
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        //cout << endl;
        level++;
    }
}
int main(){
    treenode *root    = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(7);
    root->left->right = newnode(6);
    root->right->left  = newnode(5);
    root->right->right = newnode(4);
    cout<<" spiral levelorder traversal is: ";
    spirallevelorder(root);
    return 0;
}
