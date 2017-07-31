#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int left=2*i+1;
    int r=2*i+2;
    int max=i;
    if(left<n&&arr[left]>arr[max])
        max=left;
    if(r<n&& arr[r]>arr[max])
        max=r;
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int arr[100000];
    string str;
    getline(cin,str);
    istringstream ss(str);
    int p;
    vector<int> vec;
    while(ss>>p){
        vec.push_back(p);
    }
    for(int q=0;q<vec.size();q++){
        arr[q]=vec[q];
    }
    heapsort(arr,vec.size());
    for(int q=0;q<vec.size();q++){
        cout<<arr[q]<<" ";
    }
    cout<<endl;
    return 0;
}
