#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  long long int x,y,nodes,edges;
  vector <long long int> adj[10];
  scanf("%lld",&nodes);
  scanf("%lld",&edges);
  for(long long int i=0;i<edges;i++){
    scanf("%lld%lld",&x,&y);
    adj[x].push_back(y);//Insert y in adjacency list of x
  }
  for(long long int i=1;i<=nodes;i++){
    printf("\nAdjacency list of node %lld:",i);
    for(long long int j=0;j<adj[i].size();j++){
      printf("%lld ",adj[i][j]);
    }
  }
}