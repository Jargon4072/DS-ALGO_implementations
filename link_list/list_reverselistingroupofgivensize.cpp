#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
node* reverse_in_group_size(node* head,int k){
  node* temp=new node;
  temp=NULL;
  node* prev=new node;
  prev=NULL;
  node *curr=new node;
  curr=head;
  //cout<<head->data;
  int p=0;
  while(curr!=NULL&&p!=k){
      temp=curr->next;
      curr->next=prev;
      prev=curr;
      curr=temp;
      p++;
      //cout<<curr->data;
  }
  if(temp!=NULL){
    head->next=reverse_in_group_size(temp,k);
  }
  return prev;

}

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
  node* head=new node;
  head=NULL;
  int z;
  cout<<"Enter elements of list: "<<endl;
  string str;
  getline(cin,str);
  istringstream stream(str);
  int s;
  int count=0;
  while (stream>>s) {
    head=insert(head,s);
    count++;
  }
  //  printlist(head);
  cout<<"Enter size of interval:";
  cin>>z;
  head=reverse_in_group_size(head,z);
  cout<<"list after reverse is: ";
  printlist(head);
}
