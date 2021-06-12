#include <stdio.h>
#include <stdlib.h>
int determinant(int **a){
	int temp;
	temp = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	return temp;
}

int main(){
	int n;
	int **arr;
	int det;
	arr = (int **) malloc(sizeof(int*) * 2);
	arr[0] = (int *) malloc(sizeof(int) * 2);
	arr[1] = (int *) malloc(sizeof(int) * 2);
	scanf("%d %d",&arr[0][0],&arr[0][1]);
	scanf("%d %d",&arr[1][0],&arr[1][1]);
	det = determinant(arr);
	if (det == 0){
		printf("Singular Matrix\n");
	}
	else{
		printf("Invertible Matrix\n");
		printf("%.2f %.2f\n",(float)arr[1][1] / (float)det, -1*(float)arr[0][1] / (float)det);
		printf("%.2f %.2f\n",-1*(float)arr[1][0] / (float)det, (float)arr[0][0] / (float)det);
	}
	return 0;
}

