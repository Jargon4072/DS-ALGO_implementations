#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
node* insert_end(node* head,int value){
	node* new_node=new node;
	new_node->data=value;
	if(head==NULL){
		head=new_node;
        new_node->next=head;
		return head;
	}
	node* temp=new node;
	temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
    new_node->next=head;
	temp->next=new_node;
	return head;
}
node* insert_beg(node* head,int value){
    head=insert_end(head,value);
    node* temp=new node;
	temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
    head=temp;
	return head;
}
node* insert_at_pos(node* head,int value,int pos){
	node* new_node=new node;
	new_node->data=value;
	if(head==NULL){
		head=new_node;
        new_node->next=head;
		return head;
	}
	if(pos==1){
		head=insert_beg(head,value);
		return head;
	}
	int count=1;
	node* temp=new node;
	temp=head;
	while(temp->next!=head&&count!=pos-1){
		count++;
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	return head;
}
void print_list(node* head){
	if(head==NULL){
		return;
	}
	node* temp=new node;
	temp=head;
	while(temp->next!=head){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
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
	while(1){
		cout<<"1.insert@end\n2.insert@beg\n3.insert@pos\n4.Print_list\n5.Quit\nEnter choice: ";
		int p;
		cin>>p;
		if(p==5){
			return 0;
		}
		else if(p==1){
			int val;
			cin>>val;
			head=insert_end(head,val);
		}
		else if(p==2){
			int val;
			cin>>val;
			head=insert_beg(head,val);
		}
		else if(p==3){
			cout<<"pos: ";
			int pos;
			cin>>pos;
			cout<<"Value: ";
			int val;
			cin>>val;
			head=insert_at_pos(head,val,pos);
		}
		else if(p==4){
			print_list(head);
		}
		else{
			cout<<"incorrect choice."<<endl;
		}
	}
}
