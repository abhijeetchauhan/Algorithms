#include <stdio.h>
#include "myheader.h"
void main(){
  int decimal,base,*p,i;
  printf("Enter no in decimal: ");
  scanf("%d",&decimal);
  printf("Enter base to be converted in: ");
  scanf("%d",&base);
  p=DecimalToBaseN(decimal,base);
  for(i=*p;i>0;i--){
  printf("%d",*(p+i));
  }
}
