#include <stdio.h>

void findarr(int start, int n, int* a, int* b);

int main(void){
	int n,a[8],b[8],i;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",a+i);
	}
	
	for (i=0;i<n;i++){
		if (*a != i+1){
			*b = i+1;
			findarr(1,n,a,b);
		}	
	}
	return 0;
}

void findarr(int start, int n, int* a, int* b){
	int i,j;
	if (start ==n){
		for (i=0;i<n-1;i++){
			for (j=i+1;j<n;j++){
				if (*(b+i) == *(b+j)){
					return;
				}
			}
		}
		for (i=0;i<n;i++){
			printf("%d ",*(b+i));
		}
		printf("\n");
		return;
	}
	
	
	for (i=1;i<=n;i++){
		if (*(a+start) != i){
			*(b+start) = i;
			findarr(start+1,n,a,b);
		}
	}
	return;
}
