/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-04-22T16:16:18+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-04-23T21:48:38+05:30
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

node* reverse_in_group_size(node* head, int n){
  stack<node*> mystack;
  node* current=head;
  node* prev=NULL;
  while(current!=NULL)
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
  int n;
  cin>>n;
  head=reverse(head,n);
  while(head!=NULL){
    cout<<head->val;
    head=head->next;
  }
  cout<<endl;
  return 0;
 }