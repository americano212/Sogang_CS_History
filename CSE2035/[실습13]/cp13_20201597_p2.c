#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct CoinBox{
	int n500;
	int n100;
	int n50;
	int n10;
};

int main(){
	int c;
	scanf("%d",&c);
	struct CoinBox cb;
	cb.n500 = c / 500;
	c = c % 500;
	cb.n100 = c /100;
	c = c % 100;
	cb.n50 = c / 50;
	c = c % 50;
	cb.n10 = c / 10;
	
	printf("%d\n",cb.n500);
	printf("%d\n",cb.n100);
	printf("%d\n",cb.n50);
	printf("%d\n",cb.n10);
	
	return 0;
}

