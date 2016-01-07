#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <bool> marked(1000000);
void erastosthenes(ll size,ll start=2){
  ll temp=sqrt(size);
  marked[1]=1;
  for(ll i=2;i<=temp;i++){
    if(!marked[i]){
      ll j,x=start%i;
      if(x==0)j=start;
      else{j=start+i-x;}
      for(j;j<=size;j=j+i){
        marked[j]=1;
      }
      marked[i]=0;
    }
  }
  for(ll i=start;i<=size;i++){
    if(!marked[i]){
      printf("%lld ",i);
    }
  }
}
int main(){
  int start_s=clock();
  ll size,start,t;
  scanf("%lld",&t);
  while(t--){
    fill(marked.begin(),marked.end(),false);
    scanf("%lld%lld",&start,&size);
    erastosthenes(size,start);
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
  }
  return 0;
}