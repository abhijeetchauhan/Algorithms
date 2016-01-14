#include <bits/stdc++.h>
#define ll long long int
#define pll pair<long long int,long long int>
#define f first
#define s second
using namespace std;

vector <pll> graph[1001];
ll ans[1001][1001];
int main(){
  ll start_s=clock();
  ll nodes,egdes,start,x,y,w,flag=0,stop,size;
  scanf("%lld%lld",&nodes,&egdes);
  for(ll i=0;i<egdes;i++){
    scanf("%lld%lld%lld",&x,&y,&w);
    graph[y].emplace_back(make_pair(x,w));//To easily find nodes from which edges are incoming
  }
  scanf("%lld",&start);
  // Base case
  for(ll i=1;i<=nodes;i++)ans[0][i]=LLONG_MAX;
  ans[0][start]=0;
  // Main step
  for(ll i=1;i<nodes;i++){
    for(ll j=1;j<=nodes;j++){
      ll temp=LLONG_MAX;
      size=0;
      for(auto it:graph[j]){
        //ans[i][it]=min(a[i-1][it],)
        if(ans[i-1][it.first]==LLONG_MAX)continue;
        temp=min(temp,ans[i-1][it.first]+it.second);
      }
      ans[i][j]=min(temp,ans[i-1][j]);
      if(ans[i-1][j]==ans[i][j]){
        size++;
      }
    }
    if(size==nodes){
      flag=1;
      stop=i;
      break;
    }
  }
  if(flag!=1){
    stop=nodes-1;
  }
  // Outputing
  for(ll i=1;i<=nodes;i++){
    printf("%lld ",ans[stop][i]);
  }
  printf("\n%lld\n",stop);
  ll stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
}