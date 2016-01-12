#include <stdio.h>
int main(void) {
	unsigned long long int t,n,k,i,s=0,a=0;
	scanf("%llu",&t);
	for(i=0;i<t;i++){
		scanf("%llu%llu",&n,&k);
		s=k*(k+1)/2;
		if(n>s)
		printf("-1\n");
		else
		while(n){
			if(n>=k){
				n=n-k;
				k--;
			}
			else{
				k--;
				a++;
			}
		}
		a=a+k;
		printf("%llu\n",a);
	}
	return 0;
}

