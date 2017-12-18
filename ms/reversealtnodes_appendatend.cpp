#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* revalt_appendend(node* head){
    if(head==NULL){
        return head;
    }
    node* temp=new node;
    temp=head;
    node* even_head=new node;
    even_head=NULL;
    node* prev=new node;
    prev=NULL;
    node* curr=new node;
    curr=head;
    int count=2;
    prev=curr;
    curr=curr->next;
    while(curr->next!=NULL){
        if(count%2==0){
            prev->next=curr->next;
            node* new_node=new node;
            new_node->data=curr->data;
            new_node->next=even_head;
            even_head=new_node;
            free(curr);
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        count++;
    }
    curr->next=even_head;
    return head;
}
node* insert(node* head,int value){
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
int main(){
    node* head=new node;
    head=NULL;
    string str;
    getline(cin,str);
    istringstream ss(str);
    int p;
    while(ss>>p){
        head=insert(head,p);
    }
    head=revalt_appendend(head);
    node* temp=new node;
    temp=head;
    if(head==NULL){
        return 0;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}
