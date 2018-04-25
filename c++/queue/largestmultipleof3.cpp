/*_______________________________________________________
|                                                        |
|      Author: Chandan Dwivedi                           |
|  'Life isn't about finding yourself.                   |
|          Life is about creating yourself.'             |
|_______________________________________________________*/

//find larget multiple of three from give elements of queue.
//not a completely queue based implementation.It is just implemented for elements of queue.
//the method is using property of vectors.there is a method to implement it using 3 queues.
#include<bits/stdc++.h>
using namespace std;
void largestmultipleof3(queue<int>& q){
    vector<int> vec;
    while(!q.empty()){
        vec.push_back(q.front());
        q.pop();
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
    }
    if(sum%3==0){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i];
        }
        cout<<endl;
        return;
    }
    else {
    int r=sum%3;
    int flag=0,z;
    for(int i=vec.size()-1;i>=0;i--){
        if(r==(vec[i]%3)){
            flag=1;
            z=vec[i];
            break;
        }
    }
    if(flag==1){
        vec.erase(remove(vec.begin(), vec.end(), z), vec.end());
    }
    else if(r==2){
        for(int i=0;i<vec.size();i++){
            if(r==0){
                break;
            }
            int rem=vec[vec.size()-i-1]%3;
            if(rem!=0){
                r=r-rem;
                vec.erase(remove(vec.begin(), vec.end(), vec[vec.size()-i-1]), vec.end());
            }

        }
    }
    else if(r==1){
        int count=0;
        for(int i=0;i<vec.size();i++){
            if(count==2){
                break;
            }
            if(vec[vec.size()-i-1]%3==2){
                vec.erase(remove(vec.begin(), vec.end(), vec[vec.size()-i-1]), vec.end());
                count++;
            }
        }
    }
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    cout<<"Enter elements: ";
    string str;
    getline(cin,str);
    int p;
    istringstream stream(str);
    while(stream>>p){
        q.push(p);
    }
    largestmultipleof3(q);
    return 0;
}
