#include <stdio.h>

int sum(int,int);

int main (void)
{
	int a,b,result;
	printf("Input first number: ");
	scanf("%d",&a);
	printf("Input second number: ");
	scanf("%d",&b);
	result = sum(a,b);
	printf("%d + %d = %d\n",a,b,result);
	return 0;
	
}

int sum(int a, int b)
{
	return a+b;	
}
