/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//code to swap node without swaping data.
//comments are comming :D
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};

node* insert(node* head,int val){
  node* temp=new node;
  temp->data=val;
  if(head==NULL){
    head=temp;
    temp->next=NULL;
  }
  else{
    node* new_node=new node;
    new_node=head;
    while(new_node->next!=NULL){
      new_node=new_node->next;
    }
    new_node->next=temp;
    temp->next=NULL;

  }
  return head;
}

node *swaplist(node* head,int x,int y){
  node* currx=new node;
  node* curry=new node;
  currx=head;
  curry=head;
  int countx=0,county=0;
  node* prevx=new node;
  node* prevy=new node;
  prevy=NULL;
  prevx=NULL;
  //currx=currx->next;
  //curry=curry->next;
  while(currx->data!=x){
    prevx=currx;
    countx++;
    currx=currx->next;
  }
  while(curry->data!=y){
    prevy=curry;
    county++;
    curry=curry->next;
  }
  if(currx==NULL||curry==NULL)
  {
    return head;
  }
  if(prevx!=NULL)
   prevx->next=curry;
  else
    head=curry;

  if(prevy!=NULL)
    prevy->next=currx;
  else
    head=currx;

  node* temp1=new node;
  temp1=currx->next;
  currx->next=curry->next;
  curry->next=temp1;
  return head;
}
int main(){
  int x,y;
  node* head=new node;
  head=NULL;
  string str;
  getline(cin,str);

  vector<int> vec;
  istringstream stream(str);
  int p;
  while(stream>>p){
    vec.push_back(p);
  }
  cin>>x;
  cin>>y;
  for(int i=0;i<vec.size();i++){
    head=insert(head,vec[i]);
  }
  head=swaplist(head,x,y);
  node* swapped_node=new node;
  swapped_node=head;
  while(swapped_node!=NULL){
    cout<<swapped_node->data<<" ";
    swapped_node=swapped_node->next;
  }
  cout<<endl;
  return 0;
}
