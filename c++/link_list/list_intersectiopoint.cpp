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
 node* intersection(node* head1,int n, node* head2,int m){
   node* node1=new node;
   node1=head1;
   node* node2=new node;
   node2=head2;
   //cout<<"func...n,m="<<n<<m<<endl;
   if(n>m){
     for(int i=0;i<n-m;i++){
       node1=node1->next;
     }
   }
   else{
     for(int i=0;i<n-m;i++){
       node2=node2->next;
     }
   }
   //cout<<"data at level"<<node1->data<<","<<node2->data<<endl;
   while(node1!=NULL&&node2!=NULL){
     //cout<<"checking...."<<"data="<<node1->data<<" "<<node2->data;
     if(node1->data==node2->data&&(node1->next==node2->next)){

       break;
     }
     node1=node1->next;
     node2=node2->next;
   }
   //cout<<"found..."<<node1->data<<endl;
   return node1;
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
  string str,tsr;
  int p,q;
  node* head1=new node;
  node* head2=new node;
  head1=NULL;
  head2=NULL;
  cout<<"enter elements of first loop: "<<endl;
  getline(cin,str);
  istringstream stream(str);
  int count1=0;
  int count2=0;
  while(stream>>p){
    head1=insert(head1,p);
    count1++;
  }
  //cout<<"first list is:";
  //printlist(head1);
  cout<<endl<<"enter elements of second loop: "<<endl;
  getline(cin,tsr);
  istringstream stream1(tsr);
  while(stream1>>q){
    head2=insert(head2,q);
    count2++;
  }
  //cout<<"second list is:";
  //printlist(head2);
  node* intersection_node=new node;
  //cout<<"check"<<endl;
  intersection_node=intersection(head1,count1,head2,count2);
  cout<<"intersection node is:"<<intersection_node->data<<endl;
  return 0;
}
