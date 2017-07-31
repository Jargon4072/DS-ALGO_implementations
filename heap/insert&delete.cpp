#include<bits/stdc++.h>
using namespace std;
void swap(int* x,int * y){
    int p;
    p=*x;
    *x=*y;
    *y=p;
}
class minheap{
    int *arr;
    int capacity;  //max possible size of min heap;
    int noofelements;
public:
    minheap(int capacity);
    void minheapify(int );
    int parent(int i){ return (i-1)/2;}
    int left(int i) { return (2*i+1);}
    int right(int i){ return (2*i+2); }
    int extractmin();
    void decreasekey(int i,int new_val);
    int getmin() { return arr[0];}
    void deletekey(int i);
    void insertkey(int i);
};
minheap::minheap(int cap){
    noofelements=0;
    capacity=cap;
    arr=new int[cap];
}


//here we have to find the smallest(maximum in case of maxheap) child of current node and swap it with curr node
//and continue this process until heap property is satisfied for every node. (O(logn));
void minheap::minheapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<noofelements && arr[l]<arr[i])
        smallest=l;
    if(r<noofelements && arr[r]<arr[smallest])
        smallest=r;
    if(smallest!=i){
        swap(&arr[i],&arr[smallest]);
        minheapify(smallest);
    }
}
void minheap::insertkey(int key){
    if(noofelements==capacity){
        cout<<"overflow occured."<<endl;
        return;
    }
    noofelements++;
    int i=noofelements-1;
    arr[i]=key;

    while(i!=0&&arr[parent(i)]>arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
    }
}
void minheap::decreasekey(int i,int new_val){
    arr[i]=new_val;
    while(i!=0&&arr[parent(i)]>arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
    }
}
int minheap::extractmin(){
    if(noofelements<=0)
        return INT_MAX;
    if(noofelements==1){
        noofelements--;
        return arr[0];
    }
    int p=arr[0];
    arr[0]=arr[noofelements-1];
    noofelements--;
    minheapify(0);
    return p;
}
void minheap::deletekey(int pos){
    decreasekey(pos,INT_MIN);
    extractmin();
}
int main(){
    minheap h(11);
    string str;
    getline(cin,str);
    istringstream ss(str);
    int p;
    //int i=0;
    while(ss>>p){
        cout<<p<<" ";
        h.insertkey(p);
    }
    cout<<endl;
    cout<<"Enter position of key to delete: ";
    int q;
    cin>>q;
        cout<<"deleted...."<<endl;
    h.deletekey(q);
    int x,z;
    cout<<"minimum element is: "<<h.extractmin()<<endl<<"removed minimum element!"<<endl;
    cout<<"Root element is: "<<h.getmin()<<endl;
    cout<<"Enter position and value to decrease from key: ";
    cin>>x;
    cin>>z;
    h.decreasekey(x,z);
    cout<<"done!..."<<endl;
    cout<<"root: "<<h.getmin()<<endl;
    return 0;
}
