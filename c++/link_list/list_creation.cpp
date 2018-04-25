/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//code to create a link list by insearting elements at end
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node* next;
};

//func to insert.This func inserts element at end.
struct node* insert(struct node *head,int value ){
  struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=value;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node=head;
    while(new_node->next!=NULL){
      new_node=new_node->next;
    }
    new_node->next=temp;
  }
  return head;
}
int main(){
  struct node *head=NULL;
  cout<<"Enter elements of link lists:"<<endl;
  string str;
  getline(cin,str);
  int p;
  vector<int> vec;  //look at that vector :)
  istringstream stream(str);
  while(stream>>p){
    vec.push_back(p);
  }
  for(int i=0;i<vec.size();i++){
    head=insert(head,vec[i]);
  }
  cout<<"list values are: ";
  struct node* list=(struct node*)malloc(sizeof(struct node));
  list=head;
  while(list->next!=NULL){
    cout<<list->data<<" ";
    list=list->next;
  }
  cout<<list->data<<endl; //something different ... isin't?
  return 0;
}
