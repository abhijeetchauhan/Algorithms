#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector <bool> explored;
vector <long long int> labelarr(100000);
vector <long long int> adj[100000];
long long int label;
void dfs(long long int s){
  explored[s]=true;
  //printf("%lld ",s);
  for(long long int i=0;i<adj[s].size();i++){
    if(explored[adj[s][i]]==false){
      dfs(adj[s][i]);
    }
  }
  labelarr[s]=label;
  label--;
}
int main(){
  long long int x,y,nodes,edges,start;
  scanf("%lld",&nodes);
  scanf("%lld",&edges);
  explored.resize(nodes+1);
  for(long long int i=1;i<=nodes;i++){
    explored[i]=false;
  }
  label=nodes;
  for(long long int i=0;i<edges;i++){
    scanf("%lld%lld",&x,&y);
    adj[x].push_back(y);//Insert y in adjacency list of x
  }
  for(long long int i=1;i<=nodes;i++){
    if(explored[i]==false){
      dfs(i);
    }
  }
  for(long long int i=1;i<=nodes;i++){
    printf("%lld ",labelarr[i]);
  }
}