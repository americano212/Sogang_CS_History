#include <stdio.h>
void func(int arr[],int n, int psum[][1000]);

int main(void){
	int n,arr[1000],i,a,b,psum[1000][1000];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	scanf("%d %d",&a,&b);
	
	func(arr,n,psum);
	
	printf("%d\n",*(*(psum+a)+b+1));
	
	return 0;
}

void func(int arr[],int n, int psum[][1000]){
	int i,j,sum[1000] = {0,};
	for (i=0;i<n;i++){
		if (i==0){
			*(sum+i) = *(arr+i);
		}
		else{
			*(sum+i) = *(sum+i-1) + *(arr+i);
		}
	}
	for (i=n-1;i>=0;i--){
		*(sum+i+1) = *(sum+i);
	}
	*sum = 0;
	
	
	for (i=0;i<=n;i++){
		for (j=i;j<=n;j++){
			*(*(psum+i)+j) = *(sum+j) - *(sum+i);
		}
	}
	return;
}
