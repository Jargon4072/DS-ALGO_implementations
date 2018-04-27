#include<bits/stdc++.h>
using namespace std;
void swap(int* x,int * y){
    int p;
    p=*x;
    *x=*y;
    *y=p;
}
class maxheap{
    int heap_size;
    int capacity;
    int *arr;
public:
    maxheap(int capacity);
    void maxheapify(int );
    int getmax(){return arr[0];}
    int extractmax();
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}
    void insertkey(int key);
    //void deletekey(int key);
    //void decreasekey(int i,int new_val);
};
maxheap::maxheap(int cap){
    heap_size=0;
    capacity=cap;
    arr=new int[cap];
}
void maxheap::maxheapify(int i){
    int max=i;
    int l=left(i);
    int r=right(i);
    if(l<heap_size&&arr[l]>arr[i]){
        max=l;
    }
    if(r<heap_size&&arr[r]>arr[max]){
        max=r;
    }
    if(max!=i){
        swap(&arr[i],&arr[max]);
        maxheapify(max);
    }
}
void maxheap::insertkey(int key){
    if(heap_size==capacity){
        cout<<"overflow"<<endl;
    }
    heap_size++;
    int i=heap_size-1;
    arr[i]=key;
    while(i!=0&&arr[parent(i)]<arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);

    }
}
/*void maxheap::decreasekey(int i,int new_val){
    arr[i]=new_val;
    while(i!=0&&arr[parent(i)]<arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);

    }
}*/
int maxheap::extractmax(){
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1){
        heap_size--;
        return arr[0];
    }
    int p=arr[0];
    arr[0]=arr[heap_size-1];
    heap_size--;
    maxheapify(0);
    return p;
}
/*void maxheap::deletekey(int pos){
    decreasekey(pos,INT_MAX);
    extractmax();
}*/
int main(){
    maxheap h(15);
    string str;
    getline(cin,str);
    istringstream ss(str);
    int p;
    //int i=0;
    while(ss>>p){
        h.insertkey(p);
    }
    int k;
    cin>>k;
    int ans;
    for(int i=0;i<k;i++){
        ans=h.extractmax();
    }
    cout<<ans<<endl;
    return 0;
}
