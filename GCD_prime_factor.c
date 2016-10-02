//Coded By Hartej Singh
//Find greatest common divisor using prime factors

#include<stdio.h>
#include<stdlib.h>

int isprime(int n){
	int count=0,i;
	if (n==1)
		return 0;
	for(i=2;i<=n;i++){
		if(n%i==0)
			count++;
	}
	if(count==1)
		return 1;
	else
		return 0;
}

int fib(int n){
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

void main(){
	int pf1[20];
	int pf2[20];
	int cf[20];
	int f;
	scanf("%d",&f);
	int m=fib(f+1);
	int n=fib(f+2);
	int i,j,k=0;
	for(i=0;i<20;i++){
		pf1[i]=pf2[i]=cf[i]=-1;
	}
	for(i=2;i<=m;i++){
		if(isprime(i)&&m%i==0){
			pf1[k]=i;
			k++;
		}
	}
	k=0;
	for(i=2;i<=n;i++){
		if(isprime(i)&&n%i==0){
			pf2[k]=i;
			k++;
		}
	}
	k=0;
	printf("prime factors of m: ");
	while(pf1[k]!=-1){
		printf("\t%d",pf1[k]);
		k++;
	}
	k=0;
	printf("\n");
	printf("prime factors of n: ");
	while(pf2[k]!=-1){
		printf("\t%d",pf2[k]);
		k++;
	}
	printf("\n");
	k=0;
	int count2=0;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(pf1[i]==pf2[j]&&pf1[i]!=-1&&pf2[j]!=-1){
				count2++;
				cf[k]=pf1[i];
				k++;
			}
		}
	}
	int a=0,b=0;
	int gcd2=1;
	int count=0;
	while(pf1[a]!=-1&&pf2[b]!=-1){
		count++;
		if(pf1[a]==pf2[b]){
			gcd2*=pf1[a];
			a++;
			b++;
		}
		else if(pf1[a]>pf2[b]){
			b++;
		}
		else{
			a++;
		}
	}

	k=0;
	printf("common factors: ");
	int gcd=1;
	while(cf[k]!=-1){
		printf("\t%d",cf[k]);
		gcd*=cf[k];
		k++;
	}
	printf("\nGCD: %d\t%d\n",gcd,gcd2);
	printf("COUNT:\t%d\n",count);
	printf("COUNT(2):\t%d\n",count2);
}
