#include <bits/stdc++.h>
#include "UnionFind.h"
#define ll long long int
#define pll pair<long long int , long long int>
vector <pair<ll,pll > > graph;
ll cost;
bool compare(pair<ll,pll> &t1,pair<ll,pll> &t2)
{
  return t1.first <t2.first;
}
int main(){
  ll t,nodes,edges,x,y,w;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&nodes,&edges);
    UnionFind connect(nodes+1);
    cost=0;
    for(ll i=0;i<edges;i++){
      scanf("%lld%lld%lld",&x,&y,&w);
      graph.push_back(make_pair(w,make_pair(x,y)));
      //graph.push_back(make_pair(w,make_pair(y,x))); for undirected
    }
    sort(graph.begin(),graph.end(),compare);
    for(ll i=0;i<edges;i++){
      // Find return true if they are connected
      if(!connect.Find(graph[i].second.first,graph[i].second.second)){
        connect.Union(graph[i].second.first,graph[i].second.second);
        cost+=graph[i].first;
      }
    }
    printf("%lld\n",cost);
  }
}