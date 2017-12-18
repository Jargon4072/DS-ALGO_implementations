#include<bits/stdc++.h>
using namespace std;
void rotate_mat90(vector<vector<int>>& mat,int n,int m){
    vector<vector<int>> ans(n,vector<int>(m));
    int q=0;
    for(int  i=0;i<n;i++){
        int p=0;
        for(int j=0;j<m;j++){
            ans[p++][q]=mat[i][m-j-1];
        }
        q++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    rotate_mat90(mat,n,m);
    return 0;
}
