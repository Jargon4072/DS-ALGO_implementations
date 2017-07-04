#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
node* insertatend(node* head,int value){
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
  temp->next=new_node;
  new_node->next=head;
  return head;
}
node* insertatbegning(node* head,int value){     //insertion with head is little complex,u can try with last :)
  node* new_node=new node;
  new_node->data=value;
  node* temp=new node;
  temp=head;
  while(temp->next!=head){
    temp=temp->next;
  }
  temp->next=new_node;
  new_node->next=head;
  head=temp->next;
  return head;
}
node* insertatposition(node* head,int value,int pos){
  node* new_node=new node;
  new_node->data=value;
  node* temp=new node;
  temp=head;
  for(int i=1;i<pos;i++){
    temp=temp->next;
  }
  new_node->next=temp->next;
  temp->next=new_node;
  return head;
}
node* deleteendnode(node* head){
  node* temp=new node;
  temp=head;
  node* prev=new node;
  prev=NULL;
  while(temp->next!=head){
    prev=temp;
    temp=temp->next;
  }
  prev->next=head;
  free(temp);
  return head;
}
node* deletebegningnode(node* head){
  node* temp=new node;
  temp=head;
  while(temp->next!=head){
    temp=temp->next;
  }
  temp->next=head->next;
  free(head);
  head=temp->next;
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
  while(temp!=head){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

int main(){
  node* head=new node;
  head=NULL;
  while(1){
  cout<<"1.insert"<<endl<<"2.print"<<endl<<"3.delete"<<endl<<"4.quit"<<endl<<"Enter your choice: ";
  int choice;
  cin>>choice;
  if(choice==1){
    int p;
    cout<<"1.insert at end:"<<endl<<"2.insert at begning"<<endl<<"3.insert at position"<<endl<<"Enter your choice: ";
    cin>>p;
    if(p==1){
      int val;
      cin>>val;
      head=insertatend(head,val);
    }
    if(p==2){
      int val;
      cin>>val;
      head=insertatbegning(head,val);
    }
    if(p==3){
      int val,pos;
      cin>>val;
      cin>>pos;
      head=insertatposition(head,val,pos);
    }
  }
  else if(choice==2){
    cout<<"list is: ";
    printlist(head);
  }
  else if(choice==3){
    cout<<"1.delete at end"<<endl<<"2.delete at begning"<<endl<<"3.delete at position"<<endl<<"Enter your choice: ";
    int p;
    cin>>p;
    if(p==1){
      head=deleteendnode(head);
    }
    if(p==2){
      head=deletebegningnode(head);
    }
    if(p==3){
      //head=deleteatpos(head,position);    //to be implemented ;)
    }
  }
  else{
    return 0;
  }
}
  return 0;
}
