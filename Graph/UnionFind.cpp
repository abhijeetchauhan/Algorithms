#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class unionfind{
  vector <ll> arr,size;
  // will return root of the element
  ll root (ll element){
    while(arr[element] != element)           //chase parent of current element until it reaches root.
    {
     arr[element] = arr[arr[element]];
     element=arr[element];
    }
    return element;
  }
public:
  unionfind(ll n){
    arr.resize(n);
    size.resize(n);
    for(ll i=0;i<n;i++){
      arr[i]=i;
      size[i]=1;
    }
  }
  bool find(ll x,ll y){
    return root(x)==root(y);
  }
  void weighted_union(ll x,ll y){
    ll rootx=root(x);
    ll rooty=root(y);
    if(size[rootx]<size[rooty]){
      arr[rootx]=arr[rooty];
      size[rooty]+=size[rootx];
    }
    else{
      arr[rooty]=arr[rootx];
      size[rootx]+=size[rooty];
    }
  }
};