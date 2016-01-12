#include <stdio.h>
struct tuple
{
  int low;
  int high;
  int sum;
};
typedef struct tuple tuple;
tuple FindMaxCrossingSubarray(int *a,int low,int mid,int high){
  int leftsum=0,sum=0,i,maxleft;
  for(i=mid;i>=low;i--){
    sum=sum+a[i];
    if(sum>=leftsum){
      leftsum=sum;
      maxleft=i;
    }
  }
  int rightsum=0,j,maxright;
  for(j=mid+1,sum=0;j<=high;j++){
    sum=sum+a[j];
    if(sum>=rightsum){
      rightsum=sum;
      maxright=j;
    }
  }
  tuple re;
  re.low=maxleft;
  re.high=maxright;
  re.sum=leftsum+rightsum;
  return re;
}
tuple FindMaximumSubarray(int *a,int low,int high){
	if(high==low){
    tuple b;
    b.low=low;
    b.high=high;
    b.sum=a[low];
    return  b;
  }
  else{
    int mid;
    mid=(low+high)/2;
    tuple left=FindMaximumSubarray(a,low,mid);
    tuple right=FindMaximumSubarray(a,mid+1,high);
    tuple cross=FindMaxCrossingSubarray(a,low,mid,high);
    if(left.sum>=right.sum && left.sum>=cross.sum){
      // a.low=left.low;
      // a.high=left.high;
      // a.sum=left.sum;
      return  left;
    }
    else if(right.sum>=left.sum && right.sum>=cross.sum){
      return right;
    }
    else{
      return cross;
    }
  }
}  	
void main(){
  int a[100],size,i;
  tuple answer;
  printf("Enter size: ");
  scanf("%d",&size);
  for(i=0;i<size;i++){
    scanf("%d",&a[i]);
  }
  answer=FindMaximumSubarray(a,0,size-1);
  printf("(%d,%d)=%d",answer.low+1,answer.high+1,answer.sum);
}	