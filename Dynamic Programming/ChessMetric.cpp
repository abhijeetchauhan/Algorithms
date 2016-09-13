#include <bits/stdc++.h>
using namespace std;

long long int dp[100][100][100];
pair <long long int,long long int> point;
int main(){
  int x1,y1,x2,y2,n,s,moves,i,j,k;
  scanf("%d",&n);
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  scanf("%d",&moves);
  dp[x1][y1][0]=1;
  for(i=1;i<=moves;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
        if(dp[j][k][i-1]==0){
          continue;
        }
        point = make_pair(j,k);
        if((point.first+1)<n && (point.first+1)>=0){
          dp[point.first+1][point.second][i] += dp[j][k][i-1];
          if((point.second+1)<n && (point.second+1)>=0){
            dp[point.first+1][point.second+1][i] += dp[j][k][i-1];
          }
          if((point.second+2)<n && (point.second+2)>=0){
            dp[point.first+1][point.second+2][i] += dp[j][k][i-1];
          }
          if((point.second-1)>=0 && (point.second-1)<n){
            dp[point.first+1][point.second-1][i] += dp[j][k][i-1];
          }
          if((point.second-2)>=0 && (point.second-2)<n){
            dp[point.first+1][point.second-2][i] += dp[j][k][i-1];
          }
        }
        if((point.first+2)<n && (point.first+2)>=0){
          if((point.second+1)<n && (point.second+1)>=0) {
            dp[point.first+2][point.second+1][i] += dp[j][k][i-1];
          }
          if((point.second-1)>=0 && (point.second-1)<n){
            dp[point.first+2][point.second-1][i] += dp[j][k][i-1];
          }
        }
        if((point.second+1)<n && (point.second+1)>=0){
          dp[point.first][point.second+1][i] += dp[j][k][i-1];
        }
        if((point.second-1)>=0 && (point.second-1)<n){
          dp[point.first][point.second-1][i] += dp[j][k][i-1];
        }
        if((point.first-1)>=0 && (point.first-1)<n){
          dp[point.first-1][point.second][i] += dp[j][k][i-1];
          if((point.second+1)<n && (point.second+1)>=0){
            dp[point.first-1][point.second+1][i] += dp[j][k][i-1];
          }
          if((point.second+2)<n && (point.second+2)>=0){
            dp[point.first-1][point.second+2][i] += dp[j][k][i-1];
          }
          if((point.second-1)>=0 && (point.second-1)<n){
            dp[point.first-1][point.second-1][i] += dp[j][k][i-1];
          }
          if((point.second-2)>=0 && (point.second-2)<n){
            dp[point.first-1][point.second-2][i] += dp[j][k][i-1];
          }        
        }
        if((point.first-2)>=0 && (point.first-2)<n){
          if((point.second+1)<n && [point.second]>=0){
            dp[point.first-2][point.second+1][i] += dp[j][k][i-1];
          }
          if((point.second-1)>=0 && (point.second-1)<n){
            dp[point.first-2][point.second-1][i] += dp[j][k][i-1];
          }
        }
      }
    }
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
        printf("%lld ",dp[j][k][i]);
      }
      printf("\n");
    }

    printf("%lld\n",dp[x2][y2][i]);
  }
  printf("%lld\n",dp[x2][y2][i]);
}
