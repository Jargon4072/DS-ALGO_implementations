//program to add 2 no's represented by linklist.
//i.e 5->6->3=563 & 8->4->2=842. so ans would be =563+842=1407 i.e 1->4->0->7;
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
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
int add_value_fm_list(node* head1,node* head2){
    int num1=0;
    int num2=0;
    node* t1=new node;
    t1=head1;
    while(t1!=NULL){
        num1=num1*10+t1->data;
        t1=t1->next;
    }
    node* t2=new node;
    t2=head2;
    while(t2!=NULL){
        num2=num2*10+t2->data;
        t2=t2->next;
    }
    return num1+num2;
}
int main(){
    string str1,str2;
    getline(cin,str1);
    istringstream stream(str1);
    int p;
    node* head1=new node;
    head1=NULL;
    while(stream>>p){
        head1=insert(head1,p);
    }
    getline(cin,str2);
    istringstream ss(str2);
    int q;
    node* head2=new node;
    head2=NULL;
    while(ss>>q){
        head2=insert(head2,q);
    }
    cout<<add_value_fm_list(head1,head2);
    return 0;
}
