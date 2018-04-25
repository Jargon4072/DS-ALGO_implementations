/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to find all words from CamelCase dictionary for a given pattern.
#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'A')
struct trienode{
    bool isleaf;
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
void camelcase_insert(trienode* root,string str){
    trienode* new_node=root;
    int index;
    char ch;
    for(int i=0;i<str.length();i++){
        ch=str[i];
        if(isupper(ch)){
            index=CHAR_TO_INDEX(ch);
            if(!new_node->children[index]){
                new_node->children[index]=getnode();
            }
            new_node=new_node->children[index];
        }
    }
    (new_node->word).push_back(str);
    new_node->isleaf=true;
}
void printAllWords(trienode* root){
    if (root->isleaf){
        for(string str : root->word)
            cout << str << endl;
    }
    for (int i = 0; i < 26; i++){
        trienode* child = root->children[i];
        if (child)
            printAllWords(child);
    }
}
void camelcase_search(trienode* root,string key){
    int index;
    trienode* new_node=root;
    for(int i=0;i<key.length();i++){
        index=CHAR_TO_INDEX(key[i]);
        if(!new_node->children[index])
            return;
        new_node=new_node->children[index];
    }
    /*if(new_node->isleaf){
        if(haveChildren(new_node)){
            for(int i=0;i<26;i++){
                if(new_node->children[i]){
                    new_node=new_node->children[i];
                    if(new_node->isleaf){
                        for(string str: root->word){
                            cout<<str<<endl;
                        }
                    }
                }
            }
        }
        else{
            for(string str: root->word){
                cout<<str<<endl;
            }
        }
    }*/
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
        camelcase_insert(root,vec[i]);
    cout<<"Enter key to search: "<<endl;
    string key;
    cin>>key;
    cout<<"The words Corresponding to given key are: "<<endl;
    camelcase_search(root,key);
    return 0;
}
