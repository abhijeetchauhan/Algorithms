// Tested on https://www.hackerrank.com/challenges/maxsubarray
#include <bits/stdc++.h>
#define ll long long int
#define pll pair<long long int,long long int>
#define f first
#define s second
void swap(ll &a,ll &b){a=a^b;b=a^b;a=a^b;}
using namespace std;
vector <ll> arr;
int main(){
  ll start_s=clock();
  ll t,size;
  scanf("%lld",&t);
  while(t--){
    arr.clear();
    ll ans=0,max=LLONG_MIN;
    scanf("%lld",&size);
    arr.resize(size+1);
    for(int i=0;i<size;i++){
      scanf("%lld",&arr[i]);
      if(arr[i]>0){
        ans+=arr[i];
      }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    ll p=0,h=0,m=0,k=0,j=1;
    for(ll i=0;i<size;i++){
      h=h+arr[i];
      if(h<0){
        h=0;
        j=i+1;
      }
      if(h>p){
        p=h;
      k=j;
      m=i;
      }
    }
  //  printf("%lld-(%lld,%lld)",p,m,k);
      if(p==0)printf("%lld",max);
    else printf("%lld",p);
    if(ans==0)printf(" %lld\n",max);
    else printf(" %lld\n",ans);
  }
  //ll stop_s=clock();
  //cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "\n";
}