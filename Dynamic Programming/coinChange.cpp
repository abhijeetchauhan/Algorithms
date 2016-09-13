#include <bits/stdc++.h>
using namespace std;

int a[]={1,2,5};
int fun(int sum , int pos,int c){
   cout << sum << endl;
  if(pos<0){
    return 0;
  }
  if(sum==0){
    return c;
  }
  fun(sum-a[pos],pos-1,c+1);
  fun(sum,pos-1,c);
}

int main(){
  cout << fun(6,2,0);
}