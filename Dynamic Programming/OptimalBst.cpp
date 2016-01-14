// Input : frequency for n items [assume items in sorted order]
// Goal: Compute a valid search tree that minimizes the weighted (average) search time

#include <bits/stdc++.h>
#define ll long long int
#define d double
#define pll pair<long long int,long long int>
#define f first
using namespace std;

d p[1001];
d ans[1001][1001];
int main(){
  ll start_s=clock();
  ll size,con,temp,a,b;
  scanf("%lld",&size);
  for(ll i=1;i<=size;i++){
    scanf("%lf",&p[i]);
  }
  for(ll s=0;s<size;s++){
    for(ll i=1;i<=size;i++){
      d con=0;temp=LLONG_MAX;
      for(ll k=i;k<=i+s;k++){
        con+=p[k];
      }
      printf("%lf\n",con);
      for(ll k=i;k<=i+s;k++){
        a=i>k-1?0:ans[i][k-1];
        b=k+1>i+s?0:ans[k+1][i+s];
        temp=min(temp,min(a,b));
      }
      ans[i][i+s]=con+temp;
      cout << i << ","<<i+s<< "-"<<ans[i][i+s]<< "\n";
    }
  }
  printf("%lf\n",ans[size][size-1]);
  ll stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
}