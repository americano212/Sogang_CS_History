#include <stdio.h>
void swap(int *a, int *b);
int main(void){
	int arr[9],i,j;
	printf("Input (10 numbers): ");
	scanf("%d %d %d %d %d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8],&arr[9]);
	for (i=0;i<5;i++){
		swap(&arr[i],&arr[9-i]);
	}
	for (i=0; i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	for (i=9;i>0;i--){
        for (j=0;j<i;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
	printf("Max: %d, Min: %d\n",arr[9],arr[0]);
	return 0;
}
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
