#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(str) (int)str-(int)'a'
struct trienode{
    bool isleaf;
    int index[1000];
    trienode* children[50];
};
trienode* getnewnode(void){
    trienode* new_node=NULL;
    new_node=new trienode;
    if(new_node){
        new_node->isleaf=false;
        for(int i=0;i<26;i++){
            new_node->children[i]=NULL;
        }
    }
    return new_node;
}
