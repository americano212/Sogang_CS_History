#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	float comps;
	int vec_size;
} vector;


double VectorSize_vSize(vector *v){
	double result=0;
	int i;
	int max = (*v).vec_size;
	for (i=0;i<max;i++){
		result += (v[i].comps * v[i].comps);
	}
	result = sqrt(result);
	return result;
}

double Distance_DisVector(vector *v1, vector *v2){
	double result=0;
	int i;
	int max = (*v1).vec_size;
	for (i=0;i<max;i++){
		result += (v2[i].comps - v1[i].comps)*(v2[i].comps - v1[i].comps);
	}
	result = sqrt(result);
	return result;
}

double Scalar_innerProduct(vector *v1, vector *v2){
	double result=0;
	int i;
	int max = (*v1).vec_size;
	for (i=0;i<max;i++){
		result += v2[i].comps * v1[i].comps;
	}
	return result;
}

int main(){
	int i,j;
	int n,m;
	vector *v1, *v2;
	scanf("%d",&n);
	
	v1 = (vector*)malloc(sizeof(vector)*n);
	(*v1).vec_size = n;
	for (i=0;i<n;i++){
		scanf("%f",&v1[i].comps);
	}
	scanf("%d",&m);
	
	v2 = (vector*)malloc(sizeof(vector)*m);
	(*v2).vec_size = m;
	for (i=0;i<m;i++){
		scanf("%f",&v2[i].comps);
	}
	printf("%.2lf\n",VectorSize_vSize(v1));
	printf("%.2lf\n",VectorSize_vSize(v2));
	if (n==m){
		printf("%.3lf\n",Distance_DisVector(v1,v2));
		printf("%.6lf\n",Scalar_innerProduct(v1,v2));
	}
	
	return 0;
}

