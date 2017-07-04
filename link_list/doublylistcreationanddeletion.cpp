#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* prev;
  node* next;
};
node* insertatbegning(node* head,int value){
  node* new_node=new node;
  new_node->data=value;
  new_node->prev=NULL;
  new_node->next=head;
  if(head!=NULL){
    head->prev=new_node;
  }
  head=new_node;
  return head;
}
node *insertatend(node* head,int value){
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
node* insertafternode(node* head,node* prev_node,int value ){
  node* new_node=new node;
  new_node->data=value;
  node* temp=new node;
  temp=head;
  while(temp!=prev_node){
    temp=temp->next;
  }
  new_node->next=temp->next;
  temp->next=new_node;
  new_node->prev=temp;
  return head;
}
node* insertbeforenode(node* head,node* given_node,int value){
  node* temp=new node;
  temp=head;
  node* new_node=new node;
  new_node->data=value;
  while (temp->next!=NULL&&temp->next!=given_node) {
    temp=temp->next;
  }
  new_node->prev=temp;
  new_node->next=temp->next;
  temp->next=new_node;
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
void  deletelist(node* head,node* del) {
  if(head==NULL||del==NULL){
    cout<<"nothing to delete "<<endl;
    return;
  }
  if(head==del){           //if first node to be deleted
    head=del->next;
  }
  if(del->prev!=NULL){              //not the first node
    del->prev->next=del->next;
  }
  if(del->next!=NULL){            //not the last node
    del->next->prev=del->prev;
  }
  free(del);
  return;
}

int main(){
  node* head=new node;
  head=NULL;
  while(1){
  cout<<"1.insert \n 2.print list \n 3.delete \n 4.quit \n"<<"Enter your choice:"<<endl;
  int choice;
  cin>>choice;
  if(choice==1){
    cout<<endl<<"1.insert at begning \n 2.insert at end \n 3.insert after node 4.insert before node"<<endl<<"enter your choice:";
    int p;
    int val;
    cin>>p;
    if(p==1){
      cin>>val;
      head=insertatbegning(head,val);
    }
    if(p==2){
      cin>>val;
      head=insertatend(head,val);
    }
    if(p==3){
      cin>>val;
      head=insertafternode(head,head->next->next,val);
    }
    if(p==4){
      cin>>val;
      head=insertbeforenode(head,head->next->next,val);
    }
  }
  else if(choice==2){
    printlist(head);
  }
  else if(choice==3){
    deletelist(head,head->next->next);
  }
  else{
    break;
  }
}
  return 0;
}
