/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-04-22T15:02:25+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-04-22T16:15:42+05:30
 Program to add 1 to a number represented as linked list.
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

void print_list(node* head){
  while(head!=NULL){
    cout<<head->val;
    head=head->next;
  }
  cout<<endl;
}

node* reverse(node* head){
  node* prev=NULL;
  node* node_next;
  node* temp=head;
  while(temp->next!=NULL){
    node_next=temp->next;
    temp->next=prev;
    prev=temp;
    temp=node_next;
  }
  head=temp;
  temp->next=prev;
}
node* add_1_num_list(node* head){     //yey my implementation
  node* temp=head;
  //node* temp1,prev=NULL;
  int carry=1,sum;
  while(temp!=NULL){
    sum=carry+temp->val;
    carry=(sum>=10)?1:0;
    sum=sum%10;
    temp->val=sum;
    temp=temp->next;
  }
  if(carry){
    node* newnode=new node;
    newnode->val=carry;
    newnode->next=NULL;
    temp->next=newnode;
  }
  return head;
}


 int main(){
   node* head=new node;
   head=NULL;
   string str;
   int n;
   getline(cin,str);
   istringstream stream(str);
   while(stream>>n){
     head=insert(head,n);
   }
   head=reverse(head);
   head=add_1_num_list(head);
   head=reverse(head);
   print_list(head);
   return 0;
 }