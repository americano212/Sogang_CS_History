#include <stdio.h>

int main(void){
	int N;
	printf("Input the size of matrix: ");
	scanf("%d",&N);
	int arr[N][N],unit = 1,i,j;
	int count = N,a=-1,b=0,num = 1;
	while(1){
		for (i=0; i <count; i++){
			a += unit;
			arr[a][b] = num;
			num+=1;
		}
		count -= 1;
		if (count==-1){
			break;
		}
		for (i=0; i<count; i++){
			b += unit;
			arr[a][b] = num;
			num +=1;
		}
		unit = -unit;
	}
	
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

