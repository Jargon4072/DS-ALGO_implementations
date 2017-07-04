#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int main(){
    queue<int> q;
    int n;
    int k,rmn=0;
    string str;
    getline(cin,str);
    istringstream ss{regex_replace(str,regex{R"(\{|\}|,)"}, " ")};
    vector<int> v{istream_iterator<int>{ss},istream_iterator<int>{}};
    /*istringstream stream(str);
    vector<int> v;
    int j;
    while(stream>>j){
        v.push_back(j);
    }*/
    vector<int> vec;
    for(int i=0;i<(v.size()-1);i=i+2){
        vec.push_back(v[i]-v[i+1]);
    }
    while(!q.empty())
        q.pop();
    q.push(0);
    long long sum=0;
    int id=0;
    while(q.size()<v.size()){
        id=q.back();
        sum+=vec[id];
        while(sum<0&&!q.empty())
        q.pop();
        if(q.empty())
        sum=0;
        q.push((id+1)%n);
    }
    cout<<q.front();
    return 0;
}
