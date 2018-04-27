#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
            //TODO: implement it again. https://github.com/Jargon4072/DS-ALGO_implementations/issues/13 id:12
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
        if(!temp->children[index])
            temp->children[index]=getnode();
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
int main(){
    string str1;
    getline(cin,str1);
    istringstream iss(str1);
    vector<string> vec{istream_iterator<string>{iss}, istream_iterator<string>{}};
    char output[][32] = {"Not present in trie", "Present in trie"};
    cout<<" dictionary: "<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<", ";
    }
    cout<<endl;
    trienode* root=getnode();
    for(int i=0;i<vec.size();i++)
        insert(root,vec[i]);
    cout<<"enter word to search:";
    string str;
    cin>>str;
    cout<<str<<" is "<<output[search(root,str)]<<endl;
    return 0;
}
