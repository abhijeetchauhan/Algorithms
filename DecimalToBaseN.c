#include <stdio.h>
#include "myheader.h"
void main(){
  int decimal,base;
  printf("Enter no in decimal: ");
  scanf("%d",&decimal);
  printf("Enter base to be converted in: ");
  scanf("%d",&base);
  DecimalToBaseN(decimal,base);
}
