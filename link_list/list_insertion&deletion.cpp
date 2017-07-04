/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//code for insertion and deletion in linklist.
#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

node *insertAtend(node* head,int value){
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

node *inserAtBegning(node* head,int n){
  node *temp=new node;
  temp->data=n;
  temp->next=head;
  head=temp;
  return head;
}

node *insertAtPosition(node* head,int n,int i){
  node* temp=new node;
  temp->data=n;
  if(i==0){
    temp->next=head;
    head=temp;
  }
  else{
    node *new_node=new node;
    new_node=head;
    int c=1;
    while(c!=i){
      new_node=new_node->next;
      c++;
    }
    temp->next=new_node->next;
    new_node->next=temp;
  }
  return head;
}
node *deleteAtend(node* head){
  node* temp=new node;
  temp=head;
  if(head->next==NULL){
    free(head);
    head=NULL;
  }
  else{
    node* nexttoend=new node;
    temp=temp->next;
  while(temp->next!=NULL){
    nexttoend=temp;
    temp=temp->next;
  }
  nexttoend->next=NULL;
  free(temp);
}
  return head;
}
node *deleteAtBegning(node* head){
  node* new_node=new node;
  new_node=head;
  head=new_node->next;
  free(new_node);
  return head;
}
node* deleteAtPosition(node* head,int pos){
  node* temp=new node;
  temp=head;

  int c=1;
  if(pos==1){
    head=temp->next;
    free(temp);
  }
  else{
    temp=temp->next;
    node* prev=new node;
    prev=head;
  while(c!=pos-1){
    prev=temp;
    temp=temp->next;
    c++;
  }
  prev->next=temp->next;
  free(temp);
}
return head;
}
node* deletByValue(node* head,int value){
  node* temp=new node;
  temp=head;
  int count=0;
  int x=0;
  node* test=new node;
  test=head;
  while(test->next!=NULL){
    x++;
    test=test->next;
  }
  while(temp!=NULL&&temp->data!=value){
    count++;
    temp=temp->next;
  }
  if(count==1){
    head=deleteAtBegning(head);
  }
  else if(count==x){
    head=deleteAtend(head);
  }
  else{
    head=deleteAtPosition(head,count+1);
  }

  /*node* prev=new node;
  prev=head;
  while(temp->next!=NULL&&temp->data!=value){
    prev=temp;
    temp=temp->next;
  }
  prev->next=temp->next;
  free(temp);*/
  return head;
}
int main(){
  node *head=NULL;
  while(1){
  cout<<"eter your option: "<<endl;
  cout<<"1.insert"<<endl<<"2.print list"<<endl<<"3.delete"<<endl<<"4.quit"<<endl;
  int choice;
  cin>>choice;
  if(choice==1){
    int p;
    cout<<"1.insert at end:"<<endl<<"2.insert at begning"<<endl<<"3.insert at position"<<endl<<"Enter your choice: ";
    cin>>p;
    if(p==1){
      int val;
      cin>>val;
      head=insertAtend(head,val);
    }
    if(p==2){
      int val;
      cin>>val;
      head=inserAtBegning(head,val);
    }
    if(p==3){
      int val,pos;
      cin>>val;
      cin>>pos;
      head=insertAtPosition(head,val,pos);
    }
  }
  if(choice==3){
    int p;
    cout<<"1.delete at end:"<<endl<<"2.delete at begning"<<endl<<"3.delete at position"<<endl<<"4.delete by value"<<endl<<"Enter your choice: ";
    cin>>p;
    if(p==1){
      head=deleteAtend(head);
    }
    if(p==2){
      head=deleteAtBegning(head);
    }
    if(p==3){
      int pos;
      cin>>pos;
      head=deleteAtPosition(head,pos);
    }
    if(p==4){
      int z;
      cin>>z;
      head=deletByValue(head,z);
    }
  }
  if(choice==4){
    break;
  }
  if(choice==2){
    cout<<"list is: ";
    node *test=new node;
    test=head;
    while(test->next!=NULL){
      cout<<test->data<<" ";
      test=test->next;
    }
    cout<<test->data<<endl;
  }
}
return 0;
}
