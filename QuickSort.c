#include <stdio.h>
long long int count=0;
int Partition(long long int *a,long long int l,long long int r){
  long long int x=rand()%(r-l),i,j,temp,k;
  k=(r-l)/2;
  if(a[l]>a[r] && a[l]>a[k+l]){
    if(a[k+l]>a[r]){
      x=k;
    }
    else{
      x=r-l;
    }
    // printf("1\n");
  }
  else if(a[r]>a[l] && a[r]>a[k+l]){
    if(a[k+l]>a[l]){
      x=k;
    }
    else{
      x=0;
    }
    // printf("2\n");
  }
  else{
    if(a[r]>a[l]){
      x=r-l;
    }
    else{
      x=0;
    }
    // printf("3\n");
  }
  count=count+r-l;
  // printf("l-%lld r-%lld k-%lld %lld\n",l,r,k+l,x+l);
  // for(i=0;i<=8;i++){
  //   printf("%lld",a[i]);
  // }
  // printf("\n");
  long long int p=a[x+l];
  temp=a[x+l];
  a[x+l]=a[l];
  a[l]=temp;
  // for(i=0;i<=8;i++){
  //   printf("%lld",a[i]);
  // }
  // printf("\n");
  i=l+1;
  for(j=l+1;j<=r;j++){
    if(a[j]<p){
      temp=a[j];
      a[j]=a[i];
      a[i]=temp;
      i++;
    }
  }
  temp=a[l];
  a[l]=a[i-1];
  a[i-1]=temp;
  // for(j=l;j<=r;j++){
  //   printf("%lld",a[j]);
  // }
  // printf("\np=%lld\n",i-1);
  return i-1;
}
void QuickSort(long long int *a,long long int l,long long int r){
  if(r>=l){
    if((r-l+1)==1){
      return;
    }
    else{
      long long int p=Partition(a,l,r);
      QuickSort(a,l,p-1);
      QuickSort(a,p+1,r);
    }
  }
}
int main(){
  long long int size,a[10050],i;
  // printf("Enter size of the array: ");
  // scanf("%lld",&size);
  // for(i=0;i<size;i++){
  //   scanf("%lld",&a[i]);
  // }
  FILE* fp=fopen("QuickSort.txt","r");
  if(!fp){
    printf("Error opening the file\n");
  } 
  for(i=0;!feof(fp);i++){
    fscanf(fp,"%lld",&a[i]);
  }
  size=i;
  printf("size is %lld ,%lld\n",size,a[size-1]);
  QuickSort(a,0,size-1);
  // for(i=0;i<size;i++){
  //   printf("%lld",a[i]);
  // }
  printf("\nNO of comparisions is %lld\n",count);
}