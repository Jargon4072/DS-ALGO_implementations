/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to find shortest unique prefix of given keys.
#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
int arr[100];

struct trienode{
    trienode *children[26];
    bool isleaf;
};
trienode* getnode(void){
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
void insert(trienode* root,string key){
    int level;
    int length=key.size();
    int index;
    trienode* temp=root;
    for(level=0;level<length;level++){
        index=CHAR_TO_INDEX(key[level]);
        if(!temp->children[index]){}
            temp->children[index]=getnode();
        arr[index]+=1;
        temp=temp->children[index];
    }
    temp->isleaf=true;
}

bool search(trienode* root,string key){
    int level;
    int length=key.length();
    int index;
    trienode* temp=root;
    for(level=0;level<length;level++){
        index=CHAR_TO_INDEX(key[level]);
        if(!temp->children[index]){
            return false;
        }
        temp=temp->children[index];
    }
    return (temp!=NULL&&temp->isleaf);
}
void unique_prefix(trienode* root,string key){
    int index;
    string str1;
    trienode* new_node=root;
    for(int i=0;i<key.length();i++){
        str1+=key[i];
        index=CHAR_TO_INDEX(key[i]);
        if(new_node->children[index]){
            int p=arr[index];
            if(p==1){
                break;
            }
            else{
            }
        }
        else{
            break;
        }
        new_node=new_node->children[index];
    }
    cout<<str1<<" ";
}
int main(){
    string str1;
    getline(cin,str1);
    istringstream iss(str1);
    vector<string> vec{istream_iterator<string>{iss}, istream_iterator<string>{}};
    cout<<" dictionary: "<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<", ";
    }
    cout<<endl;
    trienode* root=getnode();
    for(int i=0;i<vec.size();i++)
        insert(root,vec[i]);
    cout<<"Corresponding unique prefixes are: ";
    cout<<endl;
    for(int i=0;i<vec.size();i++){
        unique_prefix(root,vec[i]);
    }
    cout<<endl;
    return 0;
}
