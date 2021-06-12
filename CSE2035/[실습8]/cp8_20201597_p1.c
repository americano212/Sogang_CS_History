#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,m;
	int **arr;
	int i,j;
	scanf("%d %d",&n,&m);
	arr = (int **) malloc (sizeof(int*) * n);
	
	for (i=0;i<m;i++){
		arr[i] = (int *) malloc(sizeof(int)*m);
	}
	for (i=0;i<m;i++){
		arr[0][i] = 1;
	}
	for (i=0;i<n;i++){
		arr[i][0] = 1;
	}
	
	for (i=1;i<n;i++){
		for (j=1;j<m;j++){
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

