#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;


long long int i,j;
vector <pair < pair<long long int,long long int> , pair<long long int,long long int> > > g;
long long int dp[111][111];
long long int f(long long int x, long long int y){
  long long int xl,yb;
  // cout << x << "," << y << endl;
  if(x==0 && y==0){
    // cout << "yo";
    return 1;
  }
  if(x<0 || y<0){
    // cout << "no";
    return 0;
  }
  if(dp[x][y] != -1){
    return dp[x][y];
  }
  for(i=0;i<g.size();i++){
    if(x==g[i].f.f && y==g[i].f.s && (x-1)==g[i].s.f && y==g[i].s.s){
      // cout << "what";
      xl=0;
      break;
    } 
  }
  if(i==g.size()){
    xl=f(x-1,y);
  }
  for(i=0;i<g.size();i++){
    if(x==g[i].f.f && y==g[i].f.s && (x)==g[i].s.f && (y-1)==g[i].s.s){
      // cout << "what";
      yb= 0;
      break;
    } 
  }
  if(i==g.size()){
    yb=f(x,y-1);
  }  
  dp[x][y]=xl+yb;
  return xl+yb;
}

class AvoidRoads{
  public:
  long long numWays(long long int width, long long int height, vector <string> bad){
  long long int n=bad.size();
      g.clear();
  long long int x1,y1,x2,y2;
    for(long long int i=0;i<111;i++){
    for(long long int j=0;j<111;j++){
      dp[i][j]=-1;
    }
  }
  for(i=0;i<n;i++){
    sscanf(bad[i].c_str(),"%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
    g.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    g.push_back(make_pair(make_pair(x2, y2), make_pair(x1, y1)));
  }
  return f(width,height);
    
  }


};