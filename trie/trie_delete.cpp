#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(p) (int)p-(int)'a'
#define CHAR_SIZE 26
struct trienode
{
	bool isLeaf;
	trienode* character[CHAR_SIZE];
};

trienode* getnewnode(){
	trienode* node = new trienode;
	node->isLeaf = false;

	for (int i = 0; i < CHAR_SIZE; i++)
		node->character[i] = NULL;

	return node;
}
void insert(trienode* root,string key){
    int level;
    int length=key.size();
    int index;
    trienode* temp=root;
    for(level=0;level<length;level++){
        index=CHAR_TO_INDEX(key[level]);
        if(!temp->character[index])
            temp->character[index]=getnewnode();
        temp=temp->character[index];
    }
    temp->isLeaf=true;
}

bool search(trienode* head, char* str){
	if (head == NULL)
		return false;

	trienode* curr = head;
	while (*str){
		curr = curr->character[*str - 'a'];
		if (curr == NULL)
			return false;
		str++;
	}
	return curr->isLeaf;
}

bool haveChildren(trienode* curr){
	for (int i = 0; i < CHAR_SIZE; i++)
		if (curr->character[i])
			return true;
	return false;
}

bool deletion(trienode*& curr, char* str){
	if (curr == NULL)
		return false;
	if (*str){
		if (curr != NULL && curr->character[*str - 'a'] != NULL &&deletion(curr->character[*str - 'a'], str + 1) &&curr->isLeaf == false){
			free(curr);
			curr = NULL;
			return true;
		}
	}
	if (*str == '\0' && curr->isLeaf){
		if (!haveChildren(curr)){
			free(curr);
			curr = NULL;
			return true;
		}
		else{
			curr->isLeaf = false;
			return false;
		}
	}
	return false;
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
    trienode* root=getnewnode();
    for(int i=0;i<vec.size();i++)
        insert(root,vec[i]);
    while(1){
        cout<<"1.search\n2.delete\n3.quit\nEnter your choice: ";
        int p;
        cin>>p;
        if(p==1){
            cout<<"enter word to search:";
            string str;
            cin>>str;
            char *cstr = new char[str.length() + 1];
            strcpy(cstr, str.c_str());
            cout<<str<<" is "<<output[search(root,cstr)]<<endl;
        }
        else if(p==2){
            cout<<"enter word to delete:";
            string str1;
            cin>>str1;
            char *cstr1 = new char[str1.length() + 1];
            strcpy(cstr1, str1.c_str());
            deletion(root,cstr1);
        }
        else{
            break;
        }
    }
    return 0;
}
