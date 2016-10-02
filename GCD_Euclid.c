//Coded By Hartej Singh
//Find greatest common divisor using Euclid's algorithm

#include<stdio.h>
int gcd(int m,int n) //EUCLID'S ALGORITHM
{
	int r,count=0;
	while(n!=0)
	{
		count++;
		r=m%n;
		m=n;
		n=r;
	}
	printf("\n\nCOUNT : %d\n\n",count);
	return m;
}

int fib(int n){ //GENERATES FIBONACCI SERIES NUMBERS USING RECURSIVE APPRAOCH
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

void main()
{
	int no1,no2;
	int i;
	scanf("%d",&i);
	int m=fib(i+1);
	int n=fib(i+2);
	printf("\nGCD of %d and %d is: %d\n",m,n,gcd(m,n));
}
