/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'It is never too late to be what you might have been' |
|_______________________________________________________*/

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
    node* new1_node=new node;
    new1_node=head;
    while(new1_node->next!=NULL){
      new1_node=new1_node->next;
    }
    new1_node->next=temp;
  }
  return head;
}
node* merge(node* h1,node* h2){
  node* final1_node=new node;
  final1_node=NULL;
  if(h1==NULL){
    return h2;
  }
  else if(h2==NULL){
    return h1;
  }
    if(h1->data<=h2->data){
      final1_node=h1;
      final1_node->next=merge(h1->next,h2);
    }
    else{
      final1_node=h2;
      final1_node->next=merge(h2->next,h1);
    }
  return final1_node;
}
/*node* merge(node* final1_node, node* head1, node* head2){
  node* temp1=new node;
  temp1=head1;
  node* temp2=new node;
  temp2=head2;
  if(head1==NULL){
    return head2;
  }
  else if(head2==NULL){
    return head1;
  }
  else{
    while(temp1!=NULL||temp2!=NULL){
      if(temp1->data>=temp2->data){
        final1_node=insert(final1_node,temp1->data);
      }
      else{
        final1_node=insert(final1_node,temp2->data);
      }
      temp1=temp1->next;
      temp2=temp2->next;
    }
    if(temp1==NULL&&temp2!=NULL){
      while(temp2!=NULL){
        final1_node=insert(final1_node,temp2->data);
      }
    }
    if(temp2==NULL&&temp1!=NULL){
      while(temp1!=NULL){
        final1_node=insert(final1_node,temp1->data);
      }
    }
  }
  return final1_node;
}*/ //this is not working. iteration sucks :(
void printlist(node* new_node){
  node* temp3=new node;
  temp3=new_node;
  while(temp3!=NULL){
    cout<<temp3->data<<" ";
    temp3=temp3->next;
  }
  cout<<endl;
}
int main(){
  int p,q;
  string str1,str2;
  node* head1=new node;
  head1=NULL;
  node* head2=new node;
  head2=NULL;
  cout<<"Enter values for first list: ";
  getline(cin,str1);
  istringstream stream1(str1);
  while(stream1>>p){
    head1=insert(head1,p);
  }
  //cout<<"print list1"<<endl;
  //printlist(head1);
  cout<<endl<<"Enter values for second list: ";
  getline(cin,str2);
  istringstream stream2(str2);
  while(stream2>>q){
    head2=insert(head2,q);
  }
  //cout<<"print list2"<<endl;
  //printlist(head2);
  node* new_node=new node;
  new_node=NULL;
  new_node=merge(head1,head2);
  cout<<"final list"<<endl;
  printlist(new_node);
  return 0;
}
