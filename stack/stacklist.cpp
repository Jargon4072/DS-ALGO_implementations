/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//code to implement stack with linklist.
#include<bits/stdc++.h>
using namespace std;
struct stacknode{
  int data;
  stacknode* next;
};
stacknode* newnode(int value){
  stacknode* new_node=new stacknode;
  new_node->data=value;
  new_node->next=NULL;
  return new_node;
}
int isempty(stacknode* head){
  return !head;
}
stacknode* push(stacknode* head,int  value){
  stacknode* new_node=newnode(value);
  new_node->next=head;
  head=new_node;
  cout<<value<<"Pushed to stack"<<endl;
  return head;
}
stacknode* pop(stacknode* head){
  if (isempty(head))
        return head;
  cout<<head->data<<" popped from stack."<<endl;
  stacknode* temp=new stacknode;
  temp=head;
  head=head->next;
  free(temp);
  return head;
}
int peek(stacknode* head){
  return head->data;
}
int main(){
  stacknode* head=new stacknode;
  head=NULL;
  while(1){
    cout<<"1.push \n 2.pop \n 3.peek \n 4.quit \n Enter your choice: ";
    int p;
    cin>>p;
    if(p==1){
      int x;
      cout<<"Enter value: ";
      cin>>x;
      head=push(head,x);
    }
    else if(p==2){
      head=pop(head);
    }
    else if(p==3){
      int x;
      cout<<"top value: ";
      x=peek(head);
      cout<<x<<endl;
    }
    else{
      return 0;
    }
  }
}
