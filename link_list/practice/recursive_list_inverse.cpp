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
	node* temp=new node;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
	return head;
}
node* rec_rev(node* head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    node* next_ele=head->next;   //second element in list.
    head->next=NULL;
    node* curr=rec_rev(next_ele);    //will reverse elements form second element to last.
    next_ele->next=head;      //join the first element and second element.
    return curr;   //return last element as head;
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
    node* prev=NULL;
    head=rec_rev(head);
    print_list(head);
    return 0;
}
