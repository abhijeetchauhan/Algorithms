#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
  long long int x,y,nodes,edges,start,front,current;
  scanf("%lld",&nodes);
  scanf("%lld",&edges);
  vector <long long int> adj[nodes+1];

  for(long long int i=0;i<edges;i++){
    scanf("%lld%lld",&x,&y);
    adj[x].push_back(y);//Insert y in adjacency list of x
  }
  // for(long long int i=1;i<=nodes;i++){
  //   printf("\nAdjacency list of node %lld:",i);
  //   for(long long int j=0;j<adj[i].size();j++){
  //     printf("%lld ",adj[i][j]);
  //   }
  // }
  scanf("%lld",&start);
  queue<long long int> que;
  long long int level[nodes+1];
  bool val[nodes+1];
  for(long long int i=1;i<=nodes;i++){
    level[i]=-1;
    val[i]=false;
  }
  que.push(start);
  val[start]=true;
  level[start]=0;
  while(!que.empty()){
    current=que.front();
    printf("\n%lld:",current);
    que.pop();
    for(long long int i=0;i<adj[current].size();i++){
      printf("%lld ",adj[current][i]);
      if(!val[adj[current][i]]){
        val[adj[current][i]]=true;
        level[adj[current][i]]=level[current]+1;
        que.push(adj[current][i]);
      }
    }
  }
  for(long long int i=1;i<=nodes;i++){
    if(start!=i){
      if(level[i]==-1){
        printf("-1 ");
      }
      else{
        printf("%lld ",level[i]);
      }
    }
  }
  return 0;
}