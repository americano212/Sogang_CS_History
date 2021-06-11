#include <stdio.h>

int sqr(int);
void printOne(int);

int main (void)
{
	int inp;
	printf("Input: ");
	scanf("%d",&inp);
	sqr(inp);
	return 0;
}

int sqr(int inp)
{
	int result;
	result = inp*inp;
	printOne(result);
	return result;
}

void printOne(int result)
{
	printf("Result: %d\n",result);
	return;
}
