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
node* insert_beg(node* head,int value){
    node* new_node=new node;
    new_node->data=value;
    new_node->next=head;
    head=new_node;
    return head;
}
node* even_first(node* head){
    node* evenlist=NULL;
    node* evenlistend=NULL;
    node* oddlist=NULL;
    node* oddlistend=NULL;
    node* temp=head;
    if(head==NULL){
        return head;
    }
    while(temp!=NULL){
        if(temp->data%2==0){
            if(evenlist==NULL){
                evenlist=evenlistend=temp;
            }
            else{
                evenlistend->next=temp;
                evenlistend=temp;
            }
        }
        else{
            if(oddlistend==NULL){
                oddlistend=oddlist=temp;
            }
            else{
                oddlistend->next=temp;
                oddlistend=temp;
            }
        }
        temp=temp->next;
    }
    evenlistend->next=oddlist;
    head=evenlist;
    return head;
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
    head=even_first(head);
    print_list(head);
    return 0;
}
