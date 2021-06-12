#include <stdio.h>

void func(int arr[], int n,int res[][1000]);
int min(int a,int b);

int main(void){
	int i,n,arr[1000],j,res[1000][1000]={0,};
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	
	
	func(arr,n,res);
	
	for (i=0;i<n;i++){
		for (j=0;j<i+1;j++){
			printf("%d ",*(*(res+i)+j));
		}
		printf("\n");
	}
	return 0;
}
int min(int a,int b){
	int temp;
	temp = a < b ? a : b;
	return temp;
}

void func(int arr[], int n,int res[][1000]){
	int i,j;
	for (i=0;i<n;i++){
		*(*(res+n-1)+i) = *(arr+i);
	}
	
	for (i=n-2;i>=0;i--){
		for (j=0;j<=i;j++){
			*(*(res+i)+j) = min(*(*(res+i+1)+j),*(*(res+i+1)+j+1));
		}
	}
	
}

