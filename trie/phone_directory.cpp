/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to implement phone directory.
#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct trienode{          //TODO:impelement it with extra node prevnode pointing to the TrieNode which corresponds
    bool isleaf;                 //to the last entered character by the user
    trienode* children[50];
    list<string> word;
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
void phone_insert(trienode* root,string str){
    trienode* new_node=root;
    int index;
    char ch;
    for(int i=0;i<str.length();i++){
        ch=str[i];
        if(islower(ch)){
            index=CHAR_TO_INDEX(ch);
            if(!new_node->children[index]){
                new_node->children[index]=getnode();
            }
            new_node=new_node->children[index];
            (new_node->word).push_back(str);
        }
    }
    (new_node->word).push_back(str);
    new_node->isleaf=true;
}
void suffix(string str,vector<string>& vec){
    int len=str.length();
    for(int i=0;i<len;i++){
        vec.push_back(str.substr(0,len-i));
    }
}
void printAllWords(trienode* root){
    string strz;
    if(root->isleaf){
        for(string str : root->word){
            if(strcmp(strz.c_str(),str.c_str())){
                cout << str << endl;
            }
            strz=str;
        }
    }
    for (int i = 0; i < 26; i++){
        trienode* child = root->children[i];
        if (child)
            printAllWords(child);
    }
}
void phone_search(trienode* root,string key){
    int index;
    trienode* new_node=root;
    for(int i=0;i<key.length();i++){
        index=CHAR_TO_INDEX(key[i]);
        if(!new_node->children[index])
            return;
        new_node=new_node->children[index];
    }
    printAllWords(new_node);

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
        phone_insert(root,vec[i]);
    cout<<"Enter key to search: "<<endl;
    string key;
    cin>>key;
    cout<<"The words Corresponding to key  "<<endl;
    vector<string> vec1;
    suffix(key,vec1);
    for(int i=0;i<vec1.size();i++){
        cout<<vec1[i]<<" are: "<<endl;
        phone_search(root,vec1[i]);
    }
    return 0;
}
