// Finding Weighted Independent Sets in a Path Graph
#include <bits/stdc++.h>
#define ll long long int
#define pll pair<long long int,long long int>
#define f first
#define s second
using namespace std;
vector <ll> graph,IndepSet,res;
int main(){
  ll start_s=clock();
  ll size,weight;
  scanf("%lld",&size);
  // Inputing graph
  graph.emplace_back(0);
  for(ll i=1;i<=size;i++){
    scanf("%lld",&weight);
    graph.emplace_back(weight);
  }
  IndepSet.resize(size+1);
  IndepSet[0]=0;
  IndepSet[1]=graph[1];
  for(ll i=2;i<=size;i++){
    IndepSet[i]=max(IndepSet[i-1],IndepSet[i-2]+graph[i]);
  }
  for(ll i=0;i<=size;i++){
    printf("%lld ",IndepSet[i]);
  }
  ll i=size;
  while(i>0){
    if(IndepSet[i-1]>=IndepSet[i-2]+graph[i]){
      i--;// Case 1:wins
      //printf("One\n");
    }
    else{ // Case 2:wins
      //printf("Two\n");
      res.emplace_back(i);
      i-=2;
    }
  }
  printf("\nNodes:");
  for(auto it:res){
    printf("%lld ",it);
  }
  ll stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
}