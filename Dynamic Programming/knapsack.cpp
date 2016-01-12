#include <bits/stdc++.h>
#define ll long long int
#define pll pair<long long int,long long int>
#define f first
#define s second
using namespace std;

ll sack [2001][2001];
ll value [2001],weight[2001];
int main(){
  // ll start_s=clock();
  ll capacity,size;
  scanf("%lld%lld",&capacity,&size);
  for(ll i=1;i<=size;i++){
    scanf("%lld%lld",&weight[i],&value[i]);
  }  
  for(ll i=0;i<=capacity;i++){
    sack[0][i]=0;
  }
  for(ll i=1;i<=size;i++){
    for(ll j=0;j<=capacity;j++){
      if(weight[i]>j){
        sack[i][j]=sack[i-1][j];
      }
      else{
        sack[i][j]=max(sack[i-1][j],sack[i-1][j-weight[i]]+value[i]);
      }
    }
  }
  printf("%lld\n",sack[size][capacity]);
  // ll stop_s=clock();
  // cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
}