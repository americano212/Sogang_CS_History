#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *arr,n,i;
	scanf("%d",&n);
	
	arr = (int *)malloc(n*sizeof(int));
	arr[0] = 1;
	arr[1] = 1;
	for (i=2;i<n;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	
	for (i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

