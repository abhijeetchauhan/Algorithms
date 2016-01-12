#include <bits/stdc++.h>
#include "UnionFind.h"
#define ll long long int
using namespace std;
int main() {
  UnionFind gra(5);
  gra.Union(0,1);
  gra.Union(1,2);
  gra.Union(3,2);
  if(gra.Find(1,3)){
    cout << "1 and 3 are connected.\n";
  }
  if(!gra.Find(4,2)){
    cout << "4 and 2 are not connected.\n";
  }
  return 0;
}