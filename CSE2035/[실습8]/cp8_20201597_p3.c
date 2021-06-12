#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,pos_x,pos_y,j;
	int **arr,num;
	scanf("%d",&n);
	arr = (int **) malloc(sizeof(int*)*n);
	for (i=0;i<n;i++){
		arr[i] = (int *) malloc (sizeof(int) * n);
	}
	
	pos_x = n/2, pos_y = 0;
	num = 1;
	for (i=0;i<n*n;i++){
		arr[pos_y][pos_x] = num;
		if (num%n==0){
			pos_y+=1;
		}
		else{
			pos_y -= 1;
			pos_x += 1;
		}
		if (pos_y==-1){
			pos_y = n-1;
		}
		if (pos_x == n){
			pos_x = 0;
		}
		num += 1;
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

