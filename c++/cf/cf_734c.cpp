#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll binary_search(vector<ll>& vec,ll value){
    ll l=0;
    ll r=vec.size()-1;
    ll m;
    while(l<=r){
        m=l+(r-l)/2;
        if(vec[m]==value)
            break;
        if(vec[m]<value){
            l=m+1;
        }
        else
            r=m-1;
    }
    return m;
}

ll min_time(ll n,ll x,ll s,vector<ll>& ts1,vector<ll>& cs1,vector<ll>& ns2,vector<ll>& cs2){
    ll ans=n*x;
    for(ll i=0;i<ts1.size();i++){
        ll amount_left=s-cs1[i];
        if(amount_left<0)
            continue;
        ans=min(ans,(n-ns2[binary_search(cs2,amount_left)])*ts1[i]);
    }
    return ans;
}
int main(){
    ll n,m,k,x,s;
    vector<ll> ts1;
    vector<ll> cs1;
    vector<ll> ns2;
    vector<ll> cs2;
    cin>>n>>m>>k;
    cin>>x>>s;
    ll p;
    for(ll i=0;i<m;i++){
        cin>>p;
        ts1.push_back(p);
    }
    for(ll i=0;i<m;i++){
        cin>>p;
        cs1.push_back(p);
    }
    for(ll i=0;i<k;i++){
        cin>>p;
        ns2.push_back(p);
    }
    for(ll i=0;i<k;i++){
        cin>>p;
        cs2.push_back(p);
    }
    cout<<min_time(n,x,s,ts1,cs1,ns2,cs2)<<endl;
}
