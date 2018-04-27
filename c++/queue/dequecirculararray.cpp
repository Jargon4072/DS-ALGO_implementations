/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//program to implement que using array
#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
class Deque{
    int front,rear;
public:
    Deque(){
        front=0;
        rear=-1;
    }
    int arr[MAX];
    void insertatfront(int data);
    void insertatrear(int data);
    int getfront();
    int getrear();
    void deletefront();
    void deleterear();
    bool isempty();
    bool isfull();
};
void Deque::insertatrear(int data){
    rear++;
    arr[rear]=data;
}
void Deque::insertatfront(int data){
    int z=arr[front];
    int p;
    for(int i=front;i<=rear;i++){     //shifting each element by one while inserting at front.
        p=arr[i+1];
        arr[i+1]=z;
        z=p;
    }
    arr[front]=data;
    rear++;
}
void Deque::deletefront(){
    cout<<arr[front]<<" is dequeued from the queue."<<endl<<endl;
    front++;
}
void Deque::deleterear(){
    cout<<arr[rear]<<" is dequeued from the queue."<<endl<<endl;
    rear--;
}
int Deque::getfront(){
    return arr[front];
}
int Deque::getrear(){
    return arr[rear];
}
bool Deque::isempty(){
    if(rear<0)
    return true;
    else
    return false;
}
bool Deque::isfull(){
    if(rear==MAX){
        return true;
    }
    else
    return false;
}
int main(){
    struct Deque d;
    while(1)
    {
    cout<<"1.insert at front \n2.insert at rear\n3.delete rear element\n4.delete front element\n5.print rear element\n6.print front element\n7.quit\n Enter your choice: ";
    int p;
    cin>>p;
    switch(p){
      case 1:
              cout<<endl<<"Enter element: ";
              int z;
              cin>>z;
              d.insertatfront(z);
              cout<<endl;
              break;
      case 2:
              cout<<endl<<"Enter element: ";
              int l;
              cin>>l;
              d.insertatrear(l);
              cout<<endl;
              break;
      case 3:
              d.deleterear();
              break;
      case 4:
              d.deletefront();
              break;
      case 5:
              cout<<"rear element is: "<<d.getrear()<<endl<<endl;
              break;
      case 6:
              cout<<"front element is: "<<d.getfront()<<endl<<endl;
              break;
      case 7:
              return 0;
      default :
              cout<<"Wrong entry.\tTry again......"<<endl;
              break;
    }
    }
    return 0;
}
