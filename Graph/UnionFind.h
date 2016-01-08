#include <bits/stdc++.h>
using namespace std;

class UnionFind{
  vector <long long int> arr,size;
  // will return root of the element
  long long int root (long long int element){
    while(arr[element] != element)           //chase parent of current element until it reaches root.
    {
     arr[element] = arr[arr[element]];
     element=arr[element];
    }
    return element;
  }
public:
  UnionFind(long long int n){
    arr.resize(n);
    size.resize(n);
    for(long long int i=0;i<n;i++){
      arr[i]=i;
      size[i]=1;
    }
  }

  void Union(long long int x,long long int y){
    long long int rootx=root(x);
    long long int rooty=root(y);
    if(size[rootx]<size[rooty]){
      arr[rootx]=arr[rooty];
      size[rooty]+=size[rootx];
    }
    else{
      arr[rooty]=arr[rootx];
      size[rootx]+=size[rooty];
    }
  }

  bool Find(long long int x,long long int y){
    return root(x)==root(y);
  }
};