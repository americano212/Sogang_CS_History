#include <stdio.h>
double calc(int *a,int n){
	int i;
	double result,sum;
	for (i=0;i<n;i++){
		sum += *(a+i);
	}
	result = sum / (double) n;
	return result;
}

int main(void){
	int n, arr[10001],i;
	double ans;
	
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	ans = calc(arr,n);
	printf("%.2lf\n",ans);
	return 0;
}

