#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	float coef;
	int expon;
} ploy;

ploy *ploy_integral(int n,ploy *a){
	ploy *temp;
	int max = a[n-1].expon;
	int i;
	temp = (ploy*)calloc(max+2,sizeof(ploy));
	for (i=0;i<n;i++){
		temp[a[i].expon+1].coef = a[i].coef / (float)(a[i].expon+1);
	}
	return temp;
}

ploy *ploy_derivative(int n,ploy *a){
	ploy *temp;
	int max = a[n-1].expon;
	int i;
	temp = (ploy*)calloc(max+2,sizeof(ploy));
	for (i=0;i<n;i++){
		temp[a[i].expon-1].coef = a[i].coef * a[i].expon;
	}
	return temp;
}

int main(){
	int n;
	ploy *p,*ip,*dp;
	p = (ploy*)calloc(n,sizeof(ploy));
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		scanf("%f %d",&p[i].coef,&p[i].expon);
	}
	int max = p[n-1].expon;
	ip = (ploy*)calloc(max+2,sizeof(ploy));
	ip = ploy_integral(n,p);
	int z_count = max+2;
	for (i=0;i<max+2;i++){
		if (ip[i].coef == 0){
			z_count--;
		}
		
	}
	printf("Integral:1.00");
	for (i=0;i<max+2;i++){
		if (ip[i].coef != 0){
			if (ip[i].coef > 0){
				printf("+");
			}
			printf("%.2fx^%d",ip[i].coef,i);
			if (z_count==1) break;
			z_count--;
		}
		
	}
	max = p[n-1].expon;
	dp = (ploy*)calloc(max+2,sizeof(ploy));
	dp = ploy_derivative(n,p);
	z_count = max+2;
	for (i=0;i<max+2;i++){
		if (dp[i].coef == 0){
			z_count--;
		}
		
	}
	printf("\nDerivative:");
	int check = 0;
	for (i=0;i<max+2;i++){
		if (dp[i].coef != 0){
			if ((dp[i].coef > 0) && (check!=0)){
				printf("+");
			}
			if (i==0){
				printf("%.2f",dp[i].coef);
			}
			else{
				printf("%.2fx^%d",dp[i].coef,i);
			}
			if (z_count==1) break;
			z_count--;
			check=1;
		}
		
	}
	printf("\n");
	return 0;
}

