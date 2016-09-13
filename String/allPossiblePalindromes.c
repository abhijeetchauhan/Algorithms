#include "pairs.h"
#include <time.h>
#define _GNU_SOURCE
#define ll long long int
char *str[100000];
void printPal(pairs **pal1,ll size){
  ll i;
  for(i=0;i<size;i++){
      Traverse(&pal1[i]);
      printf(",");
  }
  printf("\n");
}
int main(void) {
  // ---------------------------------------------Declarations-------------------------------------------------
  clock_t time;
  time = clock();
  char *my_string;
  size_t size=100000;
  ll str_size,i,j;
  // -------------------------------------------Inputing String------------------------------------------------
  my_string = (char *) malloc (size + 1);
  //  gives back the size of the string
  str_size = getline (&my_string, &size, stdin);
  if(str_size==-1){
    printf("Error\n");
  }
  else{
    printf("Your string is : %s\n",my_string);
  }
  // ----------------------------------------------Finding all 1-palindromes----------------------------------------------
  pairs *pal[str_size/2][str_size];
  ll count[str_size/2];
  for(i=0;i<str_size/2;i++) count[i]=0;
  for(i=0;i<str_size/2;i++){
    for(j=0;j<str_size;j++)
    pal[i][j]=NULL;
  }
  for(i=0;i<str_size;i++){
    for(j=i+1;j<str_size;j++){
      if(my_string[i]==my_string[j]){
        pair no;
        no.first=i;no.second=j;
        InsertFirst(&pal[0][count[0]],no);
        InsertFirst(&pal[1][count[1]],no);
        count[0]++;
        count[1]++;
      }
    }
  }
  printf("%lld\n",count[1]);
  printPal(pal[1],count[1]);
  // -------------------------------------------------------------------------------------------------------------------
  ll k;
  for(k=2;k<str_size/2;k++){
    for(i=0;i<count[k-1];i++){
      for(j=0;j<count[0];j++){
        Check(&pal[1][j],&pal[k-1][i],&pal[k][count[k]],&count[k],k);
      }
    }
    printPal(pal[k],count[k]);
  }
  // --------------------------------------------------Calculating Running Time---------------------------------------------
  time = clock() - time;
  double time_taken = ((double)time)/CLOCKS_PER_SEC;
  printf("Time: %f seconds to execute \n", time_taken);
  return 0;
}
