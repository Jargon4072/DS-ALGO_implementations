/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/


//program to reverse linklist,iterative and recursive implementation
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
node* insert(node* head,int value){
  node* temp=new node;
  temp->data=value;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    node *test=new node;
    test=head;
    while(test->next!=NULL){
      test=test->next;
    }
    test->next=temp;
  }
  return head;
}
/*node* rev(node* head){                     //iterative approach
node* curr=new node;
node* prev=new node;
node* test=new node;
curr=head;
prev=NULL;
while(curr!=NULL){
  test=curr->next;
  curr->next=prev;
  prev=curr;
  curr=test;
}
head=prev;
return head;
}*/
node *recrev(node* head){                 //recursive apporch
  node* temp=new node;
  node* rest=new node;
  temp=head;
  rest=temp->next;
  if(head==NULL||rest==NULL){
    return head;
  }
  rest=recrev(rest);
  temp->next->next=temp;
  temp->next=NULL;
  return rest;
}

int main(){
  int p;
  string str;
  vector<int> vec;
  getline(cin,str);
  istringstream stream(str);
  //cout<<"str: "<<str<<endl;
  while(stream>>p){
    vec.push_back(p);
  }
  node* head=new node;
  head=NULL;
  for(int i=0;i<vec.size();i++){
    head=insert(head,vec[i]);
    //cout<<"list: "<<vec[i];
  }
  //cout<<endl;
  head=recrev(head);
  node* temp=new node;
  temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;

  return 0;
}
