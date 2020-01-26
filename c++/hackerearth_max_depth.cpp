/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-05-19T21:30:09+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-05-19T22:38:05+05:30
 */



#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX=10000005;
vector<ll>sides[MAX];
vector<ll> level[MAX];
ll BFS(ll arr[]){
    ll d_arr[MAX] = {};
    ll maximum = 0;
    queue<pair<ll, ll> >pair_q;
    pair_q.push({1,0});
    while(!pair_q.empty()){
        ll first = pair_q.front().first;
        ll sec = pair_q.front().second;
        maximum = max(maximum, sec);
        level[sec].push_back(arr[first]);
        pair_q.pop();
        d_arr[first] = 1;
        for(auto it:sides[first]){
            if(!d_arr[it])
              pair_q.push({it, sec + 1});
        }
    }
    for(int i = 0; i < MAX; i++)
      sort(level[i].begin(), level[i].end());
    return maximum;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    ll arr[MAX];
    for(int i = 1; i <= n; i++){
            cin >> arr[i];
    }
    for(int i = 1; i < n; i++){
        ll u, v;
        cin >> u >> v;
        sides[u].push_back(v);
        sides[v].push_back(u);
    }
    ll max_dis = BFS(arr);
    while(q--){
        ll s1, s2;
        cin >> s1 >> s2;
        s1 %= (max_dis + 1);
        auto it = lower_bound(level[s1].begin(), level[s1].end(), s2);
        ll res = -1;
        if(it != level[s1].end())
          res = *it;
        cout << res << endl;
    }
    return 0;
}