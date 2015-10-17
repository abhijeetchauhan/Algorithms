#include "myheader.h"
#include <stdbool.h>
// This is Miller-Rabin primality test (non deterministic)
// reference link-"https://www.topcoder.com/community/data-science/data-science-tutorials/primality-testing-non-deterministic-algorithms/"
/* this function calculates (a*b)%c taking into account that a*b might overflow */
unsigned long long int mulmod(unsigned long long int a,unsigned long long int b,unsigned long long int c){
    unsigned long long int x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
bool Miller(unsigned long long int p,unsigned long long int iteration){
  // Condition for no less than 2 
  if(p<2){
    return false;
  }
  // Condition for all even numbers
  if(p!=2 && p%2==0){
    return false;
  }
  // s would be even or 1
  unsigned long long s=p-1,i;
  // this is to find the s after taking out the factor which is in the of power of 2
  while(s%2==0){
    s/=2;
  }
  for(i=0;i<iteration;i++){
    // a is initialised to a random number between 0 to p
    unsigned long long a=rand()%(p-1)+1,temp=s;
    // finding the remainder of a^temp%p using modular exponention
    unsigned long long mod=ModExpo(a,temp,p);
    // main equation governing the loop is (p-1)=(2^d)*s
    // mod!=1 and mod!=p-1 is to check if the number is prime of not who's derivation comes directly from fermat's little theorem
    // temp!=p-1 is condition that makes sure that loop terminates
    while(temp!=p-1 && mod!=1 && mod!=p-1){
      // mulmod is to find (a*b)%c
      mod=mulmod(mod,mod,p);
      temp *= 2;
    }
    if(mod!=p-1 && temp%2==0){
      return false;
    }
  }
  return true;
}
void main(){
  unsigned long long int t,n,m,i;
  scanf("%llu",&t);
  while(t--){
    scanf("%llu%llu",&n,&m);
    for(i=n;i<=m;i++){
      if(Miller(i,5)){
        printf("%llu\n",i);
      }
    }
  }
}