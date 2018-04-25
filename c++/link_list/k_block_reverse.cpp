#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* insert_end(node* head,int value){
    node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}
node* reverse_k_block(node* head,int k){
    node* curr=head;
    node* prev=NULL;
    node* temp=new node;
    int p=0;
    while(curr!=NULL&&p!=k){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        p++;
    }
    if(temp){
        head->next=reverse_k_block(temp,k);
    }
    return prev;
}
void print_list(node* head){
	if(head==NULL){
		return;
	}
	node* temp=new node;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main() {
	node* head=new node;
	head=NULL;
	string str;
	cout<<"enter list: ";
	getline(cin,str);
	istringstream ss(str);
	int n;
	while(ss>>n){
		head=insert_end(head,n);
	}
    int k;
    cin>>k;
    head=reverse_k_block(head,k);
    print_list(head);
    return 0;
}
