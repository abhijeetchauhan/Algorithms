#include <bits/stdc++.h>
#define ll long long int
#define pll pair<long long int ,long long int>
using namespace std;

vector <bool> vis;
vector <ll> keys;
vector <pll> graph[100001];
ll cost;
void prim(ll start,ll nodes){
  // marking all nodes as unvisited and their keys infinite
  vis.resize(nodes+1,0);
  keys.resize(nodes+1,LLONG_MAX);
  // camparison function that forms min heap according to the second element in the pair
  class comp{public:bool operator()(pair<ll,ll> &p1,pair<ll,ll> &p2){return p1.second>p2.second;}};
  // declaring min priority queue
  priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,comp> pq;
  // pushing first node
  pq.emplace(make_pair(start,keys[start]=0));
  while(!pq.empty()){
    pll cur=pq.top();
    pq.pop();
    ll cv=cur.first,cw=cur.second;
    // if visited continue
    if(vis[cv])continue;
    vis[cv]=1;
    cost+=cw;
    for(auto i:graph[cv]){
      if(!vis[i.first] && i.second<keys[i.first]){
        pq.emplace(make_pair(i.first,keys[i.first]=i.second));
      }
    }
  }
}
int main(){
  ll t,nodes,edges,x,y,w,start;
  scanf("%lld",&t);
  while(t--){
    cost=0;
    scanf("%lld%lld",&nodes,&edges);
    for(ll i=0;i<=nodes;i++)
      graph[i].clear();
    // Making adjacency list
    for(ll i=0;i<edges;i++){
      scanf("%lld%lld%lld",&x,&y,&w);
      // emplace_back is faster than push_back as emplace_back 
      // cause it just construct value at the end of vector but 
      //push_back construct it somewhere else and then move it to the vector. 
      graph[x].emplace_back(make_pair(y,w));//Insert y in adjacency list of x with weight w
      graph[y].emplace_back(make_pair(x,w));
    }
    scanf("%lld",&start);
    prim(start,nodes);
    printf("%lld\n",cost); 
  }
  return 0;   
}