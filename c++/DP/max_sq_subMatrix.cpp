#include<bits/stdc++.h>
using namespace std;
void print_maxSubMat(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> s(n,vector<int>(m));
    for(int j=0;j<m;j++){
        s[0][j]=mat[0][j];
    }
    for(int i=0;i<n;i++){
        s[i][0]=mat[i][0];
    }
    int maximum=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]==1){
                s[i][j]=min(s[i][j-1],min(s[i-1][j],s[i-1][j-1]))+1;
            }
            else
                s[i][j]=0;
        }
    }
    int max_i=0,max_j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]>maximum){
                maximum=s[i][j];
                max_i=i;
                max_j=j;
            }
        }
    }
    for(int i=max_i;i>max_i-maximum;i--){
        for(int j=max_j;j>max_j- maximum;j--){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    print_maxSubMat(mat);
    return 0;
}
