#include <bits/stdc++.h>

#define ll long long int
using namespace std;
bool vis[100001];
ll dist[100001];
vector <pair<ll,ll> > graph[100001];

void dijkstra(ll start,ll nodes){
  // Marking all nodes not visited and distance max value possible
  for(ll i=0;i<=nodes;i++)vis[i]=0,dist[i]=LLONG_MAX;
  // camparison function that forms min heap according to the second element in the pair
  class comp{public:bool operator()(pair<ll,ll> &p1,pair<ll,ll> &p2){return p1.second>p2.second;}};
  priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,comp> pq;
  // pushing first node
  pq.emplace(make_pair(start,dist[start]=0));
  while(!pq.empty()){
    pair<ll,ll> cur=pq.top();
    pq.pop();
    ll cv=cur.first,cw=cur.second;
    // if visited continue
    if(vis[cv])continue;
    vis[cv]=1;
    for(auto i:graph[cv]){
      if(!vis[i.first] && cw+i.second<dist[i.first]){
        pq.emplace(make_pair(i.first,dist[i.first]=cw+i.second));
      }
    }
  }
}

int main(){
  ll x,y,w,nodes,edges,t,start,end;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&nodes,&edges);
    for(ll i=0;i<=nodes;i++)
      graph[i].clear();
    // Making adjacency list
    for(ll i=0;i<edges;i++){
      scanf("%lld%lld%lld",&x,&y,&w);
      // emplace_back is faster than push_back as emplace_back 
      // cause it just construct value at the end of vector but 
      //push_back construct it somewhere else and then move it to the vector. 
      graph[x].emplace_back(make_pair(y,w));//Insert y in adjacency list of x
    }
    // Outputing adjacency list for error testing
    // for(long long int i=1;i<=nodes;i++){
    //   printf("\nAdjacency list of node %lld:",i);
    //   for(long long int j=0;j<graph[i].size();j++){
    //     printf("(%lld,%lld) ",graph[i][j].first,graph[i][j].second);
    //   }
    // }
    scanf("%lld%lld",&start,&end);
    dijkstra(start,nodes);
    if(dist[end]!=LLONG_MAX)
      cout<<dist[end]<<"\n";
    else
      cout<<"NO\n";
  }

}