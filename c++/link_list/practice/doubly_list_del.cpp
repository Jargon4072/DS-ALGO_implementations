#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
    node* prev;
	node* next;
};
node* insert_end(node* head,int value){
	node* new_node=new node;
	new_node->data=value;
	new_node->next=NULL;
	if(head==NULL){
        new_node->prev=NULL;
		head=new_node;
		return head;
	}
	node* temp=new node;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
    new_node->prev=temp;
	return head;
}
node* del_beg(node* head){
    node* temp=new node;
    temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    free(temp);
    return head;
}
node* del_end(node* head){
    node* temp=new node;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}
node* del_at_pos(node* head, int pos){
    if(head==NULL){
        return head;
    }
    if(pos==1){
        head=del_beg(head);
        return head;
    }
    node* temp=new node;
    temp=head;
    int count=1;
    while(temp!=NULL&&count!=pos){
        count++;
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
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
	while(1){
		cout<<"1.del@end\n2.del@beg\n3.del@pos\n4.Print_list\n5.Quit\nEnter choice: ";
		int p;
		cin>>p;
		if(p==5){
			return 0;
		}
		else if(p==1){
			head=del_end(head);
		}
		else if(p==2){
			head=del_beg(head);
		}
		else if(p==3){
			cout<<"pos: ";
			int pos;
			cin>>pos;
			head=del_at_pos(head,pos);
		}
		else if(p==4){
			print_list(head);
		}
		else{
			cout<<"incorrect choice."<<endl;
		}
	}
}
