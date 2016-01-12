#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
vector<bool> val;

void bfs(vector <long long int> adj[],long long int start){
  if(val[start]==false){
    queue<long long int> que;
    que.push(start);
    val[start]=true;
    while(!que.empty()){
      long long int current=que.front();
      printf("%lld ",current);
      que.pop();
      for(long long int i=0;i<adj[current].size();i++){
        //printf("%lld ",adj[current][i]);
        if(!val[adj[current][i]]){
          val[adj[current][i]]=true;
          que.push(adj[current][i]);
        }
      }
    }
    printf("\n");
  }
}

int main(){
  long long int x,y,nodes,edges,start,front;
  scanf("%lld",&nodes);
  scanf("%lld",&edges);
  vector <long long int> adj[nodes+1];

  for(long long int i=0;i<edges;i++){
    scanf("%lld%lld",&x,&y);
    adj[x].push_back(y);//Insert y in adjacency list of x
    adj[y].push_back(x);
  }
  val.resize(nodes+1);
  for(long long int i=1;i<=nodes;i++){
    val[i]=false;
  }
  for(long long int i=1;i<=nodes;i++){
    bfs(adj,i);
  }
  return 0;
}
