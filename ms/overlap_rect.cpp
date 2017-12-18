#include<bits/stdc++.h>
using namespace std;
bool overlap(int l1[], int r1[], int l2[], int r2[]){
    if(l1[0]==l2[0]&&l1[1]==l2[1]&&r1[0]==r2[0]&&r1[1]==r2[0]){
        return true;
    }
    else if((r1[0]-l2[0])&&(r1[1]-l2[1])){
        return true;
    }
    else if((r2[0]-l1[0])&&(r2[1]-l1[1])){
        return true;
    }
    else
        return false;
}
int main(){
    int l1[2];
    int r1[2];
    int l2[2];
    int r2[2];
    for(int i=0;i<2;i++){
        cin>>l1[i];
    }
    for(int i=0;i<2;i++){
        cin>>r1[i];
    }
    for(int i=0;i<2;i++){
        cin>>l2[i];
    }
    for(int i=0;i<2;i++){
        cin>>r2[i];
    }
    if(overlap(l1,r1,l2,r2)){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
}
