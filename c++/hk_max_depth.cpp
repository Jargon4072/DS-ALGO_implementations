/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-05-19T21:50:38+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-05-19T22:38:42+05:30
 */



 #include<bits/stdc++.h>
 using namespace std;

 vector<int> GreaterEqual (vector<int> A, vector<int> X, vector<int> u, vector<int> L, vector<int> v) {
    // Write your code here

 }

 int main() {

     ios::sync_with_stdio(0);
     cin.tie(0);
     int N, Q;
     cin >> N >> Q;
     vector<int> A(N);
     for(int i_A=0; i_A<N; i_A++)
     {
     	cin >> A[i_A];
     }
     vector<int> u(N), v(N);
     for(int i_u=1; i_u<N; i_u++)
     {
     	cin >> u[i_u] >> v[i_u];
     }
     vector<int> L(Q), X(Q);
     for(int i_L=0; i_L<Q; i_L++)
     {
     	cin >> L[i_L] >> X[i_L];
     }
     vector<int> out_;
     out_ = GreaterEqual(A, X, u, L, v);
     cout << out_[0];
     for(int i_out_=1; i_out_<out_.size(); i_out_++)
     {
     	cout << "\n" << out_[i_out_];
     }
 }