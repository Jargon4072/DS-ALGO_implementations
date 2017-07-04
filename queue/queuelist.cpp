/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//linklist implementation of Queue.
#include<bits/stdc++.h>
using namespace std;
struct  queuenode{
    int data;
    queuenode* next;
};
queuenode* enqueue(queuenode* head,int value){
    queuenode* new_node=new queuenode;
    new_node->data=value;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return head;
    }
    queuenode* temp=new queuenode;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}
queuenode* dequeue(queuenode* head){
    queuenode* temp=head;
    if(head==NULL){
        cout<<"empty Queue. underflow condition.";
        return head;
    }
    cout<<head->data<<" is dequeued from the Queue."<<endl;
    head=head->next;
    free(temp);
    return head;
}
int frontelement(queuenode* head){
    return head->data;
}
int rearelement(queuenode* head){
    queuenode* temp=new queuenode;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp->data;
}
void showqueue(queuenode* head){
    queuenode* temp=new queuenode;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    queuenode* head=new queuenode;
    head=NULL;
    while(1)
    {
    cout<<"1.Enqueue\n2.Dequeue\n3.rear\n4.front\n5.Show elements of the Queue\n6.Quit\nEnter your choice:";
    int p;
    cin>>p;
    switch(p){
      case 1:
              cout<<"Enter element:";
              int z;
              cin>>z;
              head=enqueue(head,z);
              cout<<endl;
              break;
      case 2:
              head=dequeue(head);
              cout<<endl;
              break;
      case 3:
              cout<<"Rear element is: "<<rearelement(head)<<endl<<endl;
              break;
      case 4:
              cout<<"Front element is: "<<frontelement(head)<<endl<<endl;
              break;
      case 5:
              showqueue(head);
              cout<<endl;
              break;
      case 6:
              return 0;
      default :
              cout<<"Wrong entry.\tTry again......"<<endl<<endl;
              break;
    }
    }
    return 0;
}
