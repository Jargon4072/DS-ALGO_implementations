/**
 * @Author: Dwivedi Chandan
 * @Date:   2019-06-24T11:42:28+05:30
 * @Email:  chandandwivedi795@gmail.com
 * @Last modified by:   Dwivedi Chandan
 * @Last modified time: 2019-08-13T14:14:50+05:30
 */



#include<bits/stdc++.h>
using namespace std;
bool rec_overlap(int rec1[], int rec2[]){
  x1=rec1[0];
  y1=rec1[1];
  x2=rec1[2];
  y2=rec1[3];
  if((rec2[0]>=x1 && rec2[0]<x2)||(rec2[2]>=x1 && rec2[2]<x2)){
    retrun TRUE;
  }
  else{
    return FALSE;
  }
}
int main(){
  int rec1[1000005];
  int rec2[1000005];
  for(int i=0;i<4;i++){
    cin<<rec1[i];
  }
  for(int i=0;i<4;i++){
    cin<<rec2[i];
  }
  bool ans=rec_overlap(rec1,rec2);
  cout<<ans<<endl;
  return 0;
}