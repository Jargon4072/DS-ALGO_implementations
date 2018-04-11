#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 1000000            //NOTE: not a efficient func.
/*void swap(ll *xp, ll *yp)
{
    ll temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void troubleSort(ll arr[], ll n)
{
   ll i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-2; j++)
     {
        if (arr[j] > arr[j+2])
        {
           swap(&arr[j], &arr[j+2]);
           swapped = true;
        }
     }
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
bool isSorted(const ll *ar, ll size) {

    if (size == 0)
        return true;   // Edge case
    ll previous_value= *ar;
    while (size)
    {
       if (*ar < previous_value)
             return false;
       previous_value= *ar;

       ++ar;
       --size;
     }
     return true;
}
int main(){
  ll t;
  cin>>t;
  ll z=t;
  while(t--){
    ll n;
    cin>>n;
    ll arr[MAX];
    for(ll i=0;i<n;i++){
      cin>>arr[i];
    }
    troubleSort(arr,n);
    if(isSorted(arr,n))
      cout<<"Case "<<"#"<<z-t<<": "<<"OK"<<endl;
    else{
      for(ll i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
          cout<<"Case "<<"#"<<z-t<<": "<<i<<endl;
          break;
        }
      }
    }
  }
  return 0;
}*/
int main(){
  ll t;
  cin>>t;
  ll z=t;
  while(t--){
    ll n;
    cin>>n;
    ll arr[MAX];
    for(ll i=0;i<n;i++){
      cin>>arr[i];
    }
                               // TODO: complete this code.
  }
}
