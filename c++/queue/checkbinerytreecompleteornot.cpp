#include<bits/stdc++.h>
using namespace std;         //TODO: Try this after attempting level order tree trversal.
struct node{
    int data;
    node* left;
    node* right;
};
node* createqueue(int front,int rear){
    front=rear=0;
    node* queue=new node;
    return queue;
}
