#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* prev;
  node* next;
};
node* insert(node* head,int value){
  node* new_node=new node;
  new_node->data=value;
  new_node->next=NULL;
  node* temp=new node;
  temp=head;
  if(head==NULL){
    new_node->prev=NULL;
    head=new_node;
    return head;
  }
  while(temp->next!=NULL)
  temp=temp->next;

  temp->next=new_node;
  new_node->prev=temp;
  return head;
}
void  printlist(node* head) {
  node* temp=new node;
  temp=head;
  node* last=new node;
  last=NULL;
  cout<<"forword list: ";
  while(temp!=NULL){
    cout<<temp->data<<" ";
    last=temp;
    temp=temp->next;
  }
  cout<<endl;
  cout<<"reverse list:";
  while(last!=NULL){
    cout<<last->data<<" ";
    last=last->prev;
  }
  cout<<endl;
}

int main(){
  node* head=new node;
  head=NULL;
  cout<<"Enter elements of list: ";
  string str;
  getline(cin,str);
  istringstream stream(str);
  int p;
  while(stream>>p){
    head=insert(head,p);
  }
  cout<<"list is:"<<endl;
  printlist(head);
  return 0;
}
