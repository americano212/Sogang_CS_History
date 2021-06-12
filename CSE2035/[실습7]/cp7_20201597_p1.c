#include <stdio.h>
#include <stdlib.h>
void push_back(int **a,int *size,int value);
void pop_back(int **a,int *size);
double average(int *a, int size);
double variance(int *a,int size);
int main() {
	int n,c,size=0,get,i,j;
	int *arr;
	double avg,var;
	arr = (int *) malloc(sizeof(int)*(size));
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&c);
		if (c==1){
			scanf("%d",&get);
			size+=1;
			push_back(&arr,&size,get);
		}
		else{
			size-=1;
			pop_back(&arr,&size);
		}
		
		for (j=0;j<size;j++){
			printf("%d ",arr[j]);
		}
		printf("\n");
		
		avg =  average(arr, size);
		printf("%f ",avg);
		
		var = variance(arr, size);
		printf("%f\n",var);
	}

	return 0;
}

void push_back(int **a,int *size,int value){
	*a = realloc(*a,(*size)*sizeof(int));
	(*a)[*size-1]=value;
}

void pop_back(int **a,int *size){
	*a = realloc(*a,(*size)*sizeof(int));
}

double average(int *a, int size){
	int total=0,i;
	for (i=0;i<size;i++){
		total += a[i];
	}
	return total/(double)size;
}
double variance(int *a,int size){
	int total,i;
	double avg,sum;
	for (i=0;i<size;i++){
		total += a[i];
	}
	avg = total/(double)size;
	for (i=0;i<size;i++){
		sum += (a[i] - avg) * (a[i] - avg);
	}
	return sum / (double)size;
}
