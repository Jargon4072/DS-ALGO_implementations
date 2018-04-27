#include<bits/stdc++.h>
using namespace std;
struct listnode{
    int data;
    listnode* next;
};
listnode* insert(listnode* head,int value){
    listnode* new_node=new listnode;
    new_node->data=value;
    //new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return head;
    }
    listnode* temp=new listnode;
    temp=head;
    while(temp->next->data!=head->data){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
    return head;
}
listnode* circular_list(string str,listnode* head){
    istringstream ss(str);
    int x;
    while(ss>>x){
        head=insert(head,x);
    }
    /*listnode* temp=new listnode;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;*/
    return head;
}
bool check_circularlist(listnode* head){
    if(head==NULL)
        return true;
    listnode* temp=new listnode;
    temp=head;
    while(temp->next!=NULL){
        if(temp->next==head){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main(){
    string str;
    getline(cin,str);
    listnode* head=new listnode;
    head=NULL;
    head=circular_list(str,head);
    if(check_circularlist(head))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
