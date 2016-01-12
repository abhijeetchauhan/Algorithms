// #include <stdio.h>
// #include <stdbool.h>
// #include <math.h>
// long long int gcd(long long int a,long long int b) {
//   long long int rem;
//   while (b != 0) {
//     rem = a % b;
//     a = b;
//     b = rem;
//   }
//   return a;
// }
// long long int mulmod(long long int a,long long int b,long long int c){
//     long long int x = 0,y=a%c;
//     while(b > 0){
//         if(b%2 == 1){
//             x = (x+y)%c;
//         }
//         y = (y*2)%c;
//         b /= 2;
//     }
//     return x%c;
// }
// long long int * DecimalToBaseNr(long long int no,long long int base){
//   long long int output[100];
//   long long int *out;
//   out=output;
//   long long int i=1;
//   while(no){
//     output[i]=no%base;
//     no=no/base;
//     i++;
//   }
//   output[0]=i;
//   return out;
// }
// long long int ModExpo(long long int base,long long int decimalpower,long long int divisor){
//   long long int rem=1,i;
//   long long int *bin=DecimalToBaseNr(decimalpower,2);
//   long long int power=base%divisor;
//   for(i=1;i<bin[0];i++){
//     if(bin[i]==1)
//       rem=(rem*power)%divisor;
//     power=(power*power)%divisor;
//   }
//   return rem;
// }
// bool Miller(long long int p,long long int iteration){
//   // Condition for no less than 2 
//   if(p<2){
//     return false;
//   }
//   // Condition for all even numbers
//   if(p!=2 && p%2==0){
//     return false;
//   }
//   // s would be even or 1
//   unsigned long long s=p-1,i;
//   // this is to find the s after taking out the factor which is in the of power of 2
//   while(s%2==0){
//     s/=2;
//   }
//   for(i=0;i<iteration;i++){
//     // a is initialised to a random number between 0 to p
//     unsigned long long a=rand()%(p-1)+1,temp=s;
//     // finding the remainder of a^temp%p using modular exponention
//     unsigned long long mod=ModExpo(a,temp,p);
//     // main equation governing the loop is (p-1)=(2^d)*s
//     // mod!=1 and mod!=p-1 is to check if the number is prime of not who's derivation comes directly from fermat's little theorem
//     // temp!=p-1 is condition that makes sure that loop terminates
//     while(temp!=p-1 && mod!=1 && mod!=p-1){
//       // mulmod is to find (a*b)%c
//       mod=mulmod(mod,mod,p);
//       temp *= 2;
//     }
//     if(mod!=p-1 && temp%2==0){
//       return false;
//     }
//   }
//   return true;
// }
// long long int ran(long long int n,long long x,long long c){
//   return (x*x+c)%n;
// }
// void pollardRho(long long int number) {
//   // long long int i=1,x,y,k=2,d,n;
//   // x=rand()%number;
//   // y=x;
//   // while(1){
//   //   i++;
//   //   x=(x*x-1)%number;
//   //   d=gcd(abs(y-x),n);
//   //   if(d!=1 && d!=n){
//   //     printf("%lld",d);
//   //     return;
//   //   }
//   //   if(i==k){
//   //     y=x;
//   //     k=2*k;
//   //   }
//   // }
//   long long t=2,h=2,c=1,x,d;
//   //x=rand()%number;
//   while(d==1){
//     t=ran(number,t,1);
//     h=ran(number,ran(number,h,1),1);
//     d=gcd(abs(t-h),number);
//     if(d==1){
//       continue;
//     }
//     if(d<number){
//       printf("%lld",d);
//       return;
//     }
//   }

// }
// int main(){
//   pollardRho(8051);
// }
#include<stdio.h>
#define modu(a,b) a>b?(a-b):(b-a)
typedef unsigned long long ull;
ull pollard(ull);
ull gcd(ull,ull);
int main() {
    int n,t;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      pollard(n);
    }
return 0;
}
ull pollard(ull n) {
    ull i=1,x,y,k=2,d=1,c;
    x = rand()%n;
    y=x;
    c = rand()%n;
    while(d==1) {
      x = ((x*x)%n + c )%n;
      y = ((y*y)%n + c )%n;
      y = ((y*y)%n + c )%n;
      d = gcd(modu(x,y),n);
      printf("%lld  %lld  %lld\n",x,y,d);
    }
//    return d;
      if(d==n){
        pollard(n);
      }

     return 0;
}
ull gcd(ull a,ull b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}