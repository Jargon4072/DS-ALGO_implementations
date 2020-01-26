/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-04-22T10:52:42+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-04-22T12:30:09+05:30
 */

#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node* next;
};

node* insert(node* head,int data){
  node* temp=new node;
  temp->val=data;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    node* temp1=new node;
    temp1=head;
    while(temp1->next!=NULL){
      temp1=temp1->next;
    }
    temp1->next=temp;
  }
  return head;
}

/* int num_list(node* head){
  node* temp=new node;
  temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}
void print_middle(node* head){      // very naive approach.
  node* temp=new node;
  int count=num_list(head);
  temp=head;
  for(int i=1;i<=count/2;i++){
    temp=temp->next;
  }
  cout<<"middle element is: "<<temp->val;
}
*/
void print_middle(node* head){   //better appraoch
  node* slow_ptr=new node;
  node* fast_ptr=new node;
  slow_ptr=head;
  fast_ptr=head;
  if(head!=NULL){
  while(fast_ptr!=NULL && fast_ptr->next!=NULL){
    slow_ptr=slow_ptr->next;
    fast_ptr=fast_ptr->next->next;
  }
  cout<<"Middle element is: "<<slow_ptr->val;
}
}


int main(){
  node* head=new node;
  head=NULL;
  cout<<"Enter elements: ";
  string str;
  getline(cin,str);
  istringstream stream(str);
  int s;
  while(stream>>s){
    head=insert(head,s);
  }
  print_middle(head);
  return 0;
}

