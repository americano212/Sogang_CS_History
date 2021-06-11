#include <stdio.h>
float NN_mean(int (*x)[],int index,int N);
int main(void){
	int N,x,y,i;
	float aver;
	scanf("%d",&N);
	int Matrix[N][N];
	for (x=0;x<N;x++){
		for (y=0;y<N;y++){
			scanf("%d",&Matrix[x][y]);
		}
	}
	for (i=0;i<N;i++){
		aver= NN_mean(Matrix,i,N);
		printf("%.2f ",aver);
	}
	printf("\n");
	return 0;
}

float NN_mean(int (*x)[],int index,int N){
	int i;
	float sum;
	for (i=0;i<N;i++){
		sum+=(*x)[i*N+index];
	}
	return sum/N;
}
