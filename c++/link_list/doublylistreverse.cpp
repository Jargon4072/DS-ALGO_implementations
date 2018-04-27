#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* prev;
  node* next;
};
node* insert(node* head,int value) {
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
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=new_node;
  new_node->prev=temp;
  return head;
}
node* Reverse(node* head){               //my iterative implementation
  node* curr=new node;
  curr=head;
  node* temp=new node;
  temp=NULL;
  while(curr!=NULL){
    temp=curr->prev;
    curr->prev=curr->next;
    curr->next=temp;
    curr=curr->prev;
  }
  if(temp!=NULL){
    head=temp->prev;
  }
  return head;
}
/*
node* Reverse(node* head)
{
    struct node *current,*prev,*next;
    if(head==NULL)return NULL;
    current=head;
    prev=NULL;
    while(current!=NULL)
        {
        next=current->next;
        current->next=prev;
        current->prev=next;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}*/
/*
node* Reverse(node* node)       //recursive solution
{
  // If empty list, return
  if (!node) return NULL;

  // Otherwise, swap the next and prev
  node *temp = node->next;
  node->next = node->prev;
  node->prev = temp;

  // If the prev is now NULL, the list
  // has been fully reversed
  if (!node->prev) return node;

  // Otherwise, keep going
  return Reverse(node->prev);
}
*/
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
/*  while(head!=NULL)         //only  forword list printing (if you want)
  {
   printf("%d ", head->data);
   head = head->next;
 }*/
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
  printlist(head);
  cout<<"reverse list is:"<<endl;
  head=Reverse(head);
  printlist(head);
  return 0;
}
