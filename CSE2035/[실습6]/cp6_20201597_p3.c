#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n,i,j,k,m;
	int *arr1,*arr2,*arr3;
	arr1 = (int *)calloc(500,sizeof(int));
	arr2 = (int *)calloc(500,sizeof(int));
	arr3 = (int *)calloc(500,sizeof(int));
	scanf("%d",&n);
	arr1[0] = 1;
	arr2[0] = 1;
	for (i=0;i<n-2;i++){
		arr3[0] = arr1[0] + arr2[0];
		for (j=1;j<500;j++){
			if (arr3[j-1]>=10){
				arr3[j] = arr1[j] + arr2[j] + 1;
				arr3[j-1] -= 10;
			}
			else{
				arr3[j] = arr1[j] + arr2[j];
			}
		}
		
		for (j=0;j<500;j++){
			arr1[j] = arr2[j];
			arr2[j] = arr3[j];
		}
		
	}
	for (k=500;arr3[k]==0;k--);
	for (m=k;m>=0;m--){
		printf("%d",arr3[m]);
		
	}
	printf("\n");
	return 0;
}


