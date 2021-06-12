#include <stdio.h>
void func(int a[100][100],int b[100][100],int c[100][100],int N,int op){
	int i,j,k;
	if (op==0){
		for (i=0;i<N;i++){
			for (j=0;j<N;j++){
				*(*(c+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);
			}
		}
		
	}
	if (op==1){
		for (i=0;i<N;i++){
			for (j=0;j<N;j++){
				*(*(c+i)+j) = *(*(a+i)+j) - *(*(b+i)+j);
			}
		}
	}
	
	if (op==2){
		for (i=0;i<N;i++){
			for (j=0;j<N;j++){
				for (k=0;k<N;k++){
					*(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
				}
			}
		}
	}
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf("%d ",*(*(c+i)+j));
		}
		printf("\n");
	}
}


int main(void){
	int a[100][100],b[100][100],c[100][100]={0,},N,op;
	int i,j;
	scanf("%d",&N);
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			scanf("%d",(*(a+i)+j));
		}
	}
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			scanf("%d",(*(b+i)+j));
		}
	}
	scanf("%d",&op);
	func(a,b,c,N,op);
	
	return 0;
}

