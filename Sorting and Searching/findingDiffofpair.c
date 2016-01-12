#include <stdio.h>
#include <math.h>
void merging(long long int *a,long long int l,long long int m,long long int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i=0;j=0;k=l;
    while(n1 && n2){
      if(L[i]<R[j]){
        n1--;
        a[k]=L[i];
        i++;k++;
      }
      else{
        n2--;
        a[k]=R[j];
        j++;k++;
      }
    }
    if(n1){
      while(n1){
        n1--;
        a[k]=L[i];
        i++;k++;
      }
    }
    if(n2){
      while(n2){
        n2--;
        a[k]=R[j];
        j++;k++;
      }
    }
}
void mergeSort(long long int *arr, long long int l, long long int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merging(arr, l, m, r);
    }
}
int main(){
  long long int t,x[200002],y[200002],delx[200002],dely[200002],i,s=0,k;
  scanf("%lld",&t);
  for(i=0;i<t;i++){
    scanf("%lld%lld",&x[i],&y[i]);
  }
  mergeSort(x,0,t-1);
  mergeSort(y,0,t-1);
  // for(i=0;i<t;i++){
  //  printf("%lld ",x[i]);
  // }
  // printf("\n");
  // for(i=0;i<t;i++){
  //  printf("%lld ",y[i]);
  // }
  for(i=1;i<t;i++){
    delx[i]=abs(x[i-1]-x[i]);
    s=s+delx[i]*(t-i)*i;
    //printf("%lld ",s);
    if(s>1000000007){
      s=s%1000000007;
    }
  }
  //printf("\n");
  for(i=1;i<t;i++){
    dely[i]=abs(y[i-1]-y[i]);
    s=s+dely[i]*(t-i)*i;
    if(s>1000000007){
      s=s%1000000007;
    }
    //printf("%lld ",s);
  }
  //printf("\n");
  printf("%lld",s);
  
  return 0;
}