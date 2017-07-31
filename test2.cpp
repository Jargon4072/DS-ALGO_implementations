#include<bits/stdc++.h>

using namespace std;
struct treenode{
    char data;
    treenode* left;
    treenode* right;
};
treenode* newnode(char value){
    treenode* new_node=new treenode;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

int main(){
    /*string in,pre;
    getline(cin,in);
    getline(cin,pre);
    treenode* root;
    cout<<"in: "<<in<<endl<<"pre: "<<pre<<endl;
    int i=0;
    root=newnode(pre[i]);
    int pos=in.find(pre[i]);
    string lstrin=in.substr(0,pos);
    string rstrin=in.substr(pos+1);
    string lpre=pre.substr(1,lstrin.length());
    string rpre=pre.substr(lstrin.length()+1);
    cout<<"lstr: "<<lstrin<<endl<<"rstr: "<<rstrin<<endl;
    cout<<"lpre: "<<lpre<<endl<<"rpre: "<<rpre<<endl;
    cout<<"root->data: "<<root->data<<endl;
    */
    string str;
    getline(cin,str);
    string str1;
    int p=0;
    cout<<str<<endl;
    /*for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            cout<<"str1: "<<str1<<endl;
            vec.push_back(str1);
            p++;
            str1="";
        }
        else{
            str1+=str[i];
        }
    }*/
    istringstream iss(str);
    vector<string> vec{istream_iterator<string>{iss}, istream_iterator<string>{}};
    cout<<" words are: "<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
