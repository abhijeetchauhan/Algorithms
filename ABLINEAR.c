#include <stdio.h>
#include <stdlib.h>
void linearSearch(int *a,int b,int size);
void binarySearch(int *a,int b,int size);
void main(){
	int *a,size,ch,b,i;
	printf("Enter size of the array");
	scanf("%d",&size);
	a=(int *)malloc(sizeof(int)*size);
	if(a==0){
	printf("Error: Out of memory");}
	printf("Enter Array");
	for(i=0;i<size;i++){
	scanf("%d",a+i);}
	printf("Enter element to be searched");
	scanf("%d",&b);
	printf("1.Linear Search\n2.Binary Search\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:linearSearch(a,b,size);
	break;
	case 2:binarySearch(a,b,size);
	break;
	default:printf("Entered value is not valid");
	}
}
void linearSearch(int *a,int b,int size){
	int i;
	int flag=0;
	for(i=0;i<size;i++){
		if(b==a[i]){
		printf("Element %d is found at location %d\n",b,i);
		flag=1;}
	}
	if (flag==0)
	printf("Element %d is not found\n",b);
}
void binarySearch(int *a,int b,int size){
	int lower=0,higher=size,mid,flag=0;
	mid=(lower+higher)/2;
	while(lower<=higher){
		if(b==a[mid]){
			printf("Element %d is found at location %d\n",b,mid);
			flag=1;
		}
		if(b>a[mid]){
			lower=mid+1;
			mid=(lower+higher)/2;
		}
		else{
			higher=mid-1;
			mid=(lower+higher)/2;
		}
	}
	if(flag==0)
	printf("Element %d is not found",b);
}

