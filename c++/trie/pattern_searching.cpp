#include<bits/stdc++.h>
using namespace std;
#define max_char 256
class suffixtrienode{        //TODO: implement it again.also imp. it without classes(i.e. function call);
private:
    suffixtrienode* children[max_char];
    list<int> *indexes;
public:
    suffixtrienode(){
        indexes=new list<int>;
        for(int i=0;i<max_char;i++)
            children[i]=NULL;
    }
    void insertsuffix(string suffix,int index);
    list<int>* search(string pat);
};
class suffixtrie{
private:
    suffixtrienode root;
public:
    suffixtrie(string txt){
        for(int i=0;i<txt.length();i++)
            root.insertsuffix(txt.substr(i),i);
    }
    void search(string pat);
};
void suffixtrienode::insertsuffix(string s,int index) {
    indexes->push_front(index);
    if(s.length()>0){
        char cindex=s.at(0);
        if(children[cindex]==NULL)
            children[cindex]=new suffixtrienode();
        children[cindex]->insertsuffix(s.substr(1),index+1);
    }
}
list<int>* suffixtrienode::search(string s){
    if(s.length()==0){
        return indexes;
    }
    if(children[s.at(0)]!=NULL){
        return (children[s.at(0)])->search(s.substr(1));
    }
    else return NULL;
}
void suffixtrie::search(string pat){
    list<int>* result=root.search(pat);
    if(result==NULL)
        cout<<"pattern not found"<<endl;
    else{
        list<int>::iterator i;
        int patlen=pat.length();
        for(i=result->begin();i!=result->end();++i)
            cout<<"Pattern found at position "<< *i-patlen<<endl;
    }
}
int main(){
    cout<<"Enter string:"<<endl;
    string str;
    cin>>str;
    suffixtrie s(str);
    cout<<"Enter pattern to search:"<<endl;
    string pat;
    cin>>pat;
    s.search(pat);
    return 0;
}
