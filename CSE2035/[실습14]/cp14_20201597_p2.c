#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	float coef;
	int expon;
} ploy;

ploy *ploy_sum(int n,int m,ploy *a,ploy *b){
	ploy *temp;
	
	int i,max;
	if (a[n-1].expon >=  b[m-1].expon){
		max = a[n-1].expon;
	}
	else{
		max = b[m-1].expon;
	}
	temp = (ploy*)calloc(max,sizeof(ploy));
	for (i=0;i<n;i++){
		temp[a[i].expon-1].coef += a[i].coef;
	}
	for (i=0;i<m;i++){
		temp[b[i].expon-1].coef += b[i].coef;
	}
	
	return temp;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	ploy *p1,*p2,*result;
	p1 = (ploy*)malloc(sizeof(ploy)*n);
	p2 = (ploy*)malloc(sizeof(ploy)*m);
	int max;
	
	int i;
	for (i=0;i<n;i++){
		scanf("%f %d",&p1[i].coef,&p1[i].expon);
	}
	for (i=0;i<m;i++){
		scanf("%f %d",&p2[i].coef,&p2[i].expon);
	}
	if (p1[n-1].expon >=  p2[m-1].expon){
		max = p1[n-1].expon;
	}
	else{
		max = p2[m-1].expon;
	}
	result = (ploy*)malloc(sizeof(ploy)*max);
	result = ploy_sum(n,m,p1,p2);
	int z_count = max;
	for (i=0;i<max;i++){
		if (result[i].coef == 0){
			z_count--;
		}
	}
	for (i=0;i<max;i++){
		if (result[i].coef != 0){
			printf("%.2fx^%d",result[i].coef,i+1);
			if (z_count==1) break;
			printf("+");
			z_count--;
		}
	}
	printf("\n");
	return 0;
}

