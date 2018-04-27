/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//Queue implementation using stack;
#include<bits/stdc++.h>
using namespace std;
#define n 1111111     //just a simple placeholder to check if stack is empty.
void reversestack(stack<int>& st){
    int arr[100000];
    int k=0;
    while(st.top()!=n){
        arr[k]=st.top();
        st.pop();
        k++;
    }
    for(int i=0;i<k;i++){
        st.push(arr[i]);
    }
}
int main(){
    stack<int> st1;
    st1.push(n);
    int front=0;
    int rear=-1;
    while(1)
    {
    cout<<"1.Enqueue\n2.Dequeue\n3.rear\n4.front\n5.Quit\nEnter your choice:";
    int p;
    cin>>p;
    switch(p){
      case 1:
              cout<<"Enter element:";
              int z;
              rear++;
              cin>>z;
              st1.push(z);

              break;
      case 2:
              int y;
              reversestack(st1);
              y=st1.top();
              st1.pop();
              front++;
              cout<<y<<"is dequeued from the queue."<<endl;
              reversestack(st1);
              break;
      case 3:
              cout<<"rear element is:"<<st1.top()<<endl;
              break;
      case 4:
              reversestack(st1);
              cout<<"front element is:"<<st1.top()<<endl;
              reversestack(st1);
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
