#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long int ll;
vector <bool> explored;
long long int tim;
long long int finishtime[100000];
vector <long long int> adj[100000];
vector <long long int> graph[100000];
vector <long long int> reverse[100000];
void dfs1(long long int s){
  explored[s]=true;
  //printf("%lld ",s);
  for(long long int i=0;i<reverse[s].size();i++){
    if(explored[reverse[s][i]]==false){
      dfs1(reverse[s][i]);
    }
  }
  tim++;
  finishtime[s]=tim;
}
void dfs2(long long int s){
  explored[s]=true;
  printf("%lld ",s);
  for(long long int i=0;i<graph[s].size();i++){
    if(explored[graph[s][i]]==false){
      dfs2(graph[s][i]);
    }
  }
}
int main(){
  long long int x,y,nodes,edges,start;
  scanf("%lld",&nodes);
  scanf("%lld",&edges);
  explored.resize(nodes+1);
  for(long long int i=1;i<=nodes;i++){
    explored[i]=false;
  }
  for(long long int i=0;i<edges;i++){
    scanf("%lld%lld",&x,&y);
    adj[x].push_back(y);//Insert y in graphacency list of x
    reverse[y].push_back(x);
  }
  for(long long int i=nodes;i>0;i--){
    if(!explored[i]){
      dfs1(i);
    }
  }
  // for(long long int i=1;i<=nodes;i++){
  //   printf("%lld ",finishtime[i]);
  // }
  vector <long long int>::iterator it;
  for(ll i=1;i<=nodes;i++){
    //printf("\nfinishtime:%lld-",finishtime[i]);
    for(it=adj[i].begin();it!=adj[i].end();it++){
      graph[finishtime[i]].push_back(finishtime[*it]);
      //printf("%lld ",finishtime[*it]);
    }
  }
  // for(long long int i=1;i<=nodes;i++){
  //   printf("\nAdjacency list of node %lld:",i);
  //   for(long long int j=0;j<adj[i].size();j++){
  //     printf("%lld ",adj[i][j]);
  //   }
  // }
  // printf("\n");
  // for(long long int i=1;i<=nodes;i++){
  //   printf("\nAdjacency list of node %lld:",i);
  //   for(long long int j=0;j<graph[i].size();j++){
  //     printf("%lld ",graph[i][j]);
  //   }
  // }
  for(long long int i=1;i<=nodes;i++){
    explored[i]=false;
  }
  for(long long int i=nodes;i>0;i--){
    if(!explored[i]){
      dfs2(i);
      printf("\n");
    }
  }
}