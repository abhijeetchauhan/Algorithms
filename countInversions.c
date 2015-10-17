#include <stdio.h>
//unsigned long long int count=0;
unsigned long long int merging(unsigned long long int *a,unsigned long long int l,unsigned long long int m,unsigned long long int r){
    unsigned long long int i, j, k,count=0;
    unsigned long long int n1 = m - l + 1;
    unsigned long long int n2 =  r - m;

    /* create temp arrays */
    unsigned long long int L[n1], R[n2];

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
        count=count+n1;
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
    return count;
}
unsigned long long int mergeSort(unsigned long long int *arr, unsigned long long int l, unsigned long long int r)
{
    if (l < r)
    {
        unsigned long long int m = l+(r-l)/2,x,y,z; //Same as (l+r)/2, but avoids overflow for large l and h
        //printf("%d-%d-%d\n",l,m,r);
        x=mergeSort(arr, l, m);
        //printf("I am at second call\n");
        y=mergeSort(arr, m+1, r);
        //printf("I am at third call\n");
        z=merging(arr, l, m, r);
        //for(i=l;i<=r;i++){
        //  printf("%d ",arr[i]);
        //}
        //printf("\n");
        return x+y+z;
    }
    return 0;
}
void main(){
  unsigned long long int a[100020],size,i,count;
  // printf("Enter size: ");
  // scanf("%lld",&size);
  FILE* fp=fopen("IntegerArray.txt","r");
  if(!fp){
    printf("Error opening the file\n");
  } 
  for(i=0;!feof(fp);i++){
    fscanf(fp,"%llu",&a[i]);
  }
  // for(i=0;i<size;i++){
  //   scanf("%llu",&a[i]);
  // }
  size=i-1;
  printf("%llu\n",size);
  count=mergeSort(a,0,size-1);
  //merging(a,0,size/2-1,size-1);
  // for(i=0;i<size;i++){
  //   printf("%d ",a[i]);
  // }
  printf("%llu\n",count);
  printf("\n");
}
  
