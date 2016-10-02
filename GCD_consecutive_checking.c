//Coded By Hartej Singh
//Find greatest common divisor using consecutive integer checking

#include<stdlib.h>
#include<stdio.h>

int min(int m,int n){
	if(m==n)
		return m;
	else if(m<n)
		return m;
	else
		return n;
}


int gcd(int m,int n,int* z){
	int t=min(m,n);
	while(t!=0){
		(*z)++;
		int x=m%t;
		if(x==0){
			int y=n%t;
			if(y==0){
				return t;
			}
		t--;
		continue;
		}
	t--;
	}
	printf("No of times while loop executed:%d",*z);
	return 1;
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
	int x=0;
	int i=13;
	int m=fib(i+1);
	int n=fib(i+2);
	printf("\nGCD of %d and %d is: %d\n",m,n,gcd(m,n,&x));
	printf("No of times while loop executed: %d\n",x);
}
