int * DecimalToBaseN(int no,int base){
  int output[100];
  int *out;
  out=output;
  int i=1;
  while(no){
    output[i]=no%base;
    no=no/base;
    i++;
  }
  i--;
  output[0]=i;
  return out;
}
