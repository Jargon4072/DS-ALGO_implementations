#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
struct trienode{
    bool isleaf;
    int data;
    trienode* children[2];
};
trienode* getnewnode(void){
    trienode* new_node=new trienode;
    new_node->data=0;
    if(new_node){
        new_node->isleaf=false;
        for(int i=0;i<2;i++){
            new_node->children[i]=NULL;
        }
    }
    return new_node;
}
void insert(trienode* root,int key){
    trienode* new_node=root;
    bool bits;
    for(int i=31;i>=0;i--){
        bits=(key&(1<<i));
        if(!new_node->children[bits])
            new_node->children[bits]=getnewnode();
        new_node=new_node->children[bits];
    }
    new_node->isleaf=true;
    new_node->data=key;
}
int calculate_min_xor(trienode* root,int key){
    //cout<<"calculate_min_xor......."<<endl;
    bool bits;
    int ans;
    trienode* new_node=root;
    for(int i=31;i>=0;i--){
        bits=(key&(1<<i));
        if(new_node->children[bits]){
            new_node=new_node->children[bits];
        }
        else if(new_node->children[1-bits]){
            new_node=new_node->children[1-bits];
        }
    }
    ans=key^(new_node->data);
    //cout<<"xor: "<<ans<<endl;
    return ans;
}
int min_xor(trienode* root,int arr[],int n){
    int minxor=INT_MAX;
    insert(root,arr[0]);
    for(int i=1;i<n;i++){
        minxor=min(minxor,calculate_min_xor(root,arr[i]));
        insert(root,arr[i]);
    }
    return minxor;
}
int main(){
    trienode* root=getnewnode();
    int arr[MAX];
    cout<<"Enter elements of array: "<<endl;
    string str;
    getline(cin,str);
    istringstream ss(str);
    int p,i=0;
    while(ss>>p){
        arr[i]=p;
        i++;
    }
    int n=i;
    //cout<<"calculating ...."<<endl;
    int ans=min_xor(root,arr,n);
    cout<<"Mimimum XOR is: "<<ans<<endl;
    return 0;
}
