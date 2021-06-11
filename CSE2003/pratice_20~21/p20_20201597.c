#include <stdio.h>
int main(void){ 
	int n,x,sum=0,count=0;
	printf("Number of class: ");
	scanf("%d",&n);
	printf("Cutline: ");
	scanf("%d",&x);

	int arr[n];
	for (int i=0; i<n; i++){
		printf("Input score #%d: ",i);
		scanf("%d",&arr[i]);
		sum += arr[i];
		if (arr[i]<x){
			count += 1;
		}
	}
	printf("Average score: %.2f\n",(float)sum/n);
	printf("Number of failures: %d\n",count);
	return 0;
}
