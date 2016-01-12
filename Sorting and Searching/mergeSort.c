#include <stdio.h>

void merging(long long int *a,long long int l,long long int m,long long int r){
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;

    /* create temp arrays */
    long long int L[n1], R[n2];

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
        long long int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        //printf("%d-%d-%d\n",l,m,r);
        mergeSort(arr, l, m);
        //printf("I am at second call\n");
        mergeSort(arr, m+1, r);
        //printf("I am at third call\n");
        merging(arr, l, m, r);
        //for(i=l;i<=r;i++){
        //  printf("%d ",arr[i]);
        //}
        //printf("\n");
    }
}
void main(){
  long long int a[100],size,i;
  printf("Enter size: ");
  scanf("%d",&size);
  for(i=0;i<size;i++){
    scanf("%d",&a[i]);
  }
  mergeSort(a,0,size-1);
  //merging(a,0,size/2-1,size-1);
  for(i=0;i<size;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
  
