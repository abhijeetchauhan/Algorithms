#include <stdio.h>
#include <stdlib.h>
void push(int p[],int *,int item);
void pop(int p[],int *);
void main(){
  int size,p[10],value,loc,i,ch,flag=1,top=-1,*topp;
  topp=&top;
  while(flag==1){
    printf("Enter Operation to be done\n1.Push\n2.Pop\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:  printf("Enter value\n");
               scanf("%d",&value);
               push(p,topp,value);
               break;
      case 2:   pop(p,topp);
                break;
      default:  printf("invalid input\n");

    }
    printf("Enter zero to stop or one to perform another Operation");
    scanf("%d",&flag);
  }
  for(i=0;i<=top;i++){
    printf("%d",p[i]);
  }
}
void push(int p[],int *topp,int item){
  if(*topp>=2)
    printf("Overflow\n");
  else{
  *topp=*topp+1;
  p[*topp]=item;
  }
}
void pop(int p[],int *topp){
  int item;
  if(*topp==-1)
    printf("Underflow\n");
  else{
  item=p[*topp];
  *topp=*topp-1;
  } 
}