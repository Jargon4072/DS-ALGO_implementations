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
void removeloop(node* loopnode,node* head1){
  node* test=new node;
  node* list=new node;
  list=head1;
  while(1){
    test=loopnode;
    while(test->next!=loopnode&&test->next!=list)
      test=test->next;
    if(test->next==list)
    break;

    list=list->next;

  }
    test->next=NULL;
}
void loop(node* head){
  node *curr=new node;
  curr=head;
  node *prev=new node;
  prev=head;
  while(curr&&prev&&curr->next){
    prev=prev->next;
    curr=curr->next->next;
    if(curr==prev){
      cout<<"Detected loop"<<endl<<"removing..."<<endl;
      removeloop(prev,head);
      cout<<"loop removed"<<endl;
      break;
    }
  }
}

void printlist(node* new_node1){
  node* temp3=new node;
  temp3=new_node1;
  while(temp3!=NULL){
    cout<<temp3->data<<" ";
    temp3=temp3->next;
  }
  cout<<endl;
}
int main(){
  node* head=new node;
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
    //head->next->next->next->next->next = head->next->next;
    loop(head);
  }
  cout<<"list after removing loop";
  printlist(head);

}
