/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//sliding window to find maximum of every subarray(actually subvector :)
#include<bits/stdc++.h>
using namespace std;
void maxsubarray(vector<int>& vec,int k){
    deque<int> q;
    for(int i=0;i<k;i++){
        //stores useful index to deque.
        while((!q.empty())&&vec[i]>=vec[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(int i=k;i<vec.size();i++){
        cout<<vec[q.front()]<<" ";
        while((!q.empty())&&q.front()<=i-k){    //pop the idex of element of last window.
            q.pop_front();
        }
        while((!q.empty())&&vec[i]>=vec[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<vec[q.front()];
}
int main(){
    int k;
    cin>>k;
    string str;
    cin.ignore();
    getline(cin,str);
    int p;
    istringstream stream(str);
    vector<int> vec;
    while(stream>>p){
        vec.push_back(p);
    }
    maxsubarray(vec,k);
    return 0;
}
