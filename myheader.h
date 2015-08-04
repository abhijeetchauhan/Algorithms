void DecimalToBaseN(int no,int base){
  int output[100];
  int i=0;
  while(no){
    output[i]=no%base;
    no=no/base;
    i++;
  }
  i--;
  while(i>=0){
    printf("%d",output[i]);
    i--;
  }
  printf("\n");
}