/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//array implementation of Queue.
#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
class Queue{
  int rear,front;

public:
  int arr[MAX];
  Queue(){
    rear=-1;
    front=0;
  }
  void enqueue(int data);
  int dequeue();
  bool isempty();
  int rearelement();
  int frontelement();
};

void Queue::enqueue(int data){
  if(rear>=MAX){
    cout<<"overflow occured!."<<endl;
    return;
  }
  rear++;
  arr[rear]=data;
}
int Queue::dequeue(){
  if(rear==-1){
    cout<<"underflow occured!."<<endl;
    return 0;
  }
  int p=front;
  front++;
  return arr[p];
}
bool Queue::isempty(){
  if(rear<0){
    return true;
  }
  return false;
}
int Queue::rearelement(){
  if(rear<0){
    cout<<"Empty Queue."<<endl;
    return 0;
  }
  return arr[rear];
}
int Queue::frontelement(){
  if(rear<0&&front==0){
    cout<<"Empty Queue."<<endl;
    return 0;
  }
  return arr[front];
}
int main(){
  struct Queue q;
  while(1)
  {
  cout<<"1.Enqueue\n2.Dequeue\n3.rear\n4.front\n5.Quit\nEnter your choice:";
  int p;
  cin>>p;
  switch(p){
    case 1:
            cout<<"Enter element:";
            int z;
            cin>>z;
            q.enqueue(z);
            break;
    case 2:
            int y;
            y=q.dequeue();
            cout<<y<<"is dequeued from the queue."<<endl;
            break;
    case 3:
            cout<<"rear element is:"<<q.rearelement()<<endl;
            break;
    case 4:
            cout<<"front element is:"<<q.frontelement()<<endl;
            break;
    case 5:
            return 0;
    default :
            cout<<"Wrong entry.\tTry again......"<<endl;
            break;
  }
  }
  return 0;
}
