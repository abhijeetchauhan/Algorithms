#include <stdio.h>
#include <stdlib.h>
void add(int *p,int size,int insert,int loc);
void delete(int *p,int size,int insert,int loc);
void travel(int *p,int size);
void main(){
  int size,p[100],insert,loc,i,ch,flag=1;
  printf("Enter the size of the array\n"); 
  scanf("%d",&size);
  printf("Enter array\n");
  for(i=0;i<size;i++){
    scanf("%d",&p[i]);
  }
  printf("entered array is \n");
    for(i=0;i<size;i++){
    printf("%d",p[i]);
  }
  printf("\n");
  while(flag==1){
    printf("Enter Operation to be done\n1.Insertion\n2.Deleltion\n3.Traversing\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:  printf("Enter value and location\n");
               scanf("%d%d",&insert,&loc);
               add(p,size,insert,loc);
               size++;
               break;
      case 2:   printf("Enter value and location\n");
                scanf("%d%d",&insert,&loc);
                delete(p,size,insert,loc);
                size--;
                break;
      case 3:   travel(p,size);
                break;
      default:  printf("invalid input\n");

    }
    printf("Enter zero to stop or one to perform another Operation");
    scanf("%d",&flag);
  }
}
void add(int p[100],int size,int insert,int loc){
  int i;
  for(i=size-1;i>=loc-1;i--){
    p[i+1]=p[i];
  }
  i++;
  p[i]=insert;
}
void delete(int p[100],int size,int insert,int loc){
  int i,item;
  item=p[loc-1];
  for(i=loc-1;i<size-1;i++){
    p[i]=p[i+1];
  }
}
void travel(int p[100],int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d",p[i]);
  }
}