#include <stdio.h>
void merging(int a[100][2],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1][2], R[n2][2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++){
        L[i][0] = a[l + i][0];
        L[i][1] = a[l + i][1];

      }

    for(j = 0; j < n2; j++){
        R[j][0] = a[m + 1+ j][0];
        R[j][1] = a[m + 1+ j][1];
      }
    i=0;j=0;k=l;
    while(n1 && n2){
      if(L[i][0]<R[j][0]){
        n1--;
        a[k][0]=L[i][0];
        a[k][1]=L[i][1];
        i++;k++;
      }
      else{
        n2--;
        a[k][0]=R[j][0];
        a[k][1]=R[j][1];
        j++;k++;
      }
    }
    if(n1){
      while(n1){
        n1--;
        a[k][0]=L[i][0];
        a[k][1]=L[i][1];
        i++;k++;
      }
    }
    if(n2){
      while(n2){
        n2--;
        a[k][0]=R[j][0];
        a[k][1]=R[j][1];
        j++;k++;
      }
    }
}
void mergeSort(int arr[100][2], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2,i; //Same as (l+r)/2, but avoids overflow for large l and h
        printf("%d-%d-%d\n",l,m,r);
        mergeSort(arr, l, m);
        printf("I am at second call\n");
        mergeSort(arr, m+1, r);
        printf("I am at third call\n");
        merging(arr, l, m, r);
        for(i=l;i<=r;i++){
          printf("(%d,%d)",arr[i][0],arr[i][1]);
        }
        printf("\n");
    }
}
void main(){
  int a[100][2],size,i,j;
  printf("Enter size: ");
  scanf("%d",&size);
  for(i=0;i<size;i++){
    scanf("%d",&a[i][0]);
    a[i][1]=i+1;
  }
  mergeSort(a,0,size-1);
  //merging(a,0,size/2-1,size-1);
  for(i=0;i<size;i++){
    printf("(%d,%d)",a[i][0],a[i][1]);
  }
  printf("\n");
}