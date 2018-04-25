#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
node* insert(node* head,int value){
  node* new_node=new node;
  new_node->data=value;
  if(head==NULL){
    head=new_node;
    new_node->next=head;
    //cout<<"data: "<<head->data;
    return head;
  }
  node* temp=new node;
  temp=head;
  while(temp->next->data!=head->data){
    temp=temp->next;
    //cout<<"data: "<<temp->data;
  }
  temp->next=new_node;
  new_node->next=head;
  return head;
}
void printlist(node* head){
  if(head==NULL){
    cout<<"Empty list!"<<endl;
    return;
  }
  node* temp=new node;
  temp=head;
  cout<<head->data<<" ";
  temp=temp->next;
  while(temp->data!=head->data){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
  node* head=new node;
  head=NULL;
  string str;
  cout<<"Enter elements of list: ";
  getline(cin,str);
  int p;
  istringstream stream(str);
  while(stream>>p){
    head=insert(head,p);
  }
  cout<<"List is: ";
  printlist(head);
}
