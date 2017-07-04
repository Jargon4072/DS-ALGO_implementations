/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//floyed's cycle algo implementation
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
node *insert(node* head,int value){
  node *temp=new node;
  temp->data=value;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    node* new_node=new node;
    new_node=head;
    while(new_node->next!=NULL){
      new_node=new_node->next;
    }
    new_node->next=temp;
  }
  return head;
}

bool loop(node* head){
  node *curr=new node;
  curr=head;
  node *prev=new node;
  prev=head;
  while(curr&&prev&&curr->next){
    prev=prev->next;
    curr=curr->next->next;
    if(curr==prev){
      return true;
    }
  }
  return false;
}
int main(){
  node *head=new node;
  head=NULL;
  string str;
  getline(cin,str);
  int p;
  istringstream stream(str);
  while(stream>>p){
    head=insert(head,p);
  }
  if(head==NULL||head->next==NULL){
    cout<<"insufficient element,loop not possible:"<<endl;
    return 0;
  }
  else{
    head->next->next->next->next=head;
    bool looptest=loop(head);
    if(looptest){
      cout<<"loop found"<<endl;
    }
    else{
      cout<<"No loop"<<endl;
    }
    return 0;
  }

}
