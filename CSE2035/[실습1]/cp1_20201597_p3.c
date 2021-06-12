#include <stdio.h>
void calc (int *a,int *b, char op){
	if (op=='+'){
		*a += *b;
	}
	if (op=='-'){
		*a -= *b;
	}
	if (op=='*'){
		*a *= *b;
	}
	if (op=='/'){
		*a /= *b;
	}
	return;
}

int main(void){
	char op;
	int a,b;
	int *ans;
	
	scanf("%c",&op);
	scanf("%d %d",&a,&b);
	calc(&a,&b,op);
	printf("%d\n",a);
	
	return 0;
}
