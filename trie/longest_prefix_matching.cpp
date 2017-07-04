/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to find longest prefix matching.
#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(z) (int)z-(int)'a'
struct trienode{
    bool isleaf;
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
void insert(trienode* root,string key){
    int index;
    trienode* new_node=root;
    for(int i=0;i<key.length();i++){
        index=CHAR_TO_INDEX(key[i]);
        if(!new_node->children[index]){
            new_node->children[index]=getnewnode();
        }
        new_node=new_node->children[index];
    }
    new_node->isleaf=true;
}
bool search(trienode* root,string key){
    if(root==NULL)
        return false;
    int index;
    trienode* new_node=root;
    for(int i=0;i<key.length();i++){
        index=CHAR_TO_INDEX(key[i]);
        if(!new_node->children[index]){
            return false;
        }
        new_node=new_node->children[index];
    }
    return (new_node!=NULL&&new_node->isleaf);
}
void prefixmatching(trienode* root,string str){
    trienode* new_node=root;
    int index;
    string str1;
    int level;
    for(int i=0;i<str.length();i++){
        index=CHAR_TO_INDEX(str[i]);
        if(new_node->children[index]){
            str1+=str[i];
            if(new_node->isleaf){
                level=i;
            }
        }
        else{
            break;
        }
        new_node=new_node->children[index];
    }
    if(search(root,str1)){
        cout<<endl<<str1<<endl;
    }
    else{
        cout<<endl<<str1.substr(0,level);
    }
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
    trienode* root=getnewnode();
    for(int i=0;i<vec.size();i++)
        insert(root,vec[i]);
    while(1){
        cout<<"\n1.search prefix\n2.quit\nEnter your choice: ";
        int z;
        cin>>z;
        if(z==1){
            cout<<"enter word to search prefix: "<<endl;
            string str;
            cin>>str;
            prefixmatching(root,str);
        }
        else
            break;
    }
    return 0;
}
