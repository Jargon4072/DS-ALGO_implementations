#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
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
int kthsmallestelementmorris(treenode* root, int value){ //TODO: implement it again after implementing inorder traversal without recursion or stack; https://github.com/Jargon4072/DS-ALGO_implementations/issues/1 id:0
    int count=0;
    int ksmall=INT_MIN;
    treenode* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            count++;
            if(count==value){
                ksmall=curr->data;
            }
            curr=curr->right;
        }
        else{
            treenode* pre=curr->left;
            while(pre->right!=NULL&&pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                count++;
                if(count==value){
                    ksmall=curr->data;
                }
                curr=curr->right;
            }
        }
    }
    return ksmall;
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
    int n1;
    cin>>n1;
    cout<<n1<<" smallest element is: "<<kthsmallestelementmorris(root,n1)<<endl;
    return 0;
}
