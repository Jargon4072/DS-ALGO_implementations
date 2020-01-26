/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-04-22T12:47:37+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-04-22T14:02:44+05:30

 Program to remove duplicates from linked list.
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

node* withoutdup(node* head){    //goo implimentation but requires extra space for creation of map
  map<int,int> m;
  node* prev=NULL;
  node* curr=head;
  while(curr!=NULL){
    m[curr->val]++;
    //cout<<m[curr->val]<<" curr_val"<<endl;
    if(m[curr->val]>1){
      prev->next=curr->next;
      curr=curr->next;
      //cout<<"duplicate deleted"<<endl;
    }
    else{
      prev=curr;
      curr=curr->next;
    }
  }
  return head;
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
   head=withoutdup(head);
   while(head!=NULL){
     cout<<head->val<<" ";
     head=head->next;
   }
   cout<<endl;
   return 0;
 }