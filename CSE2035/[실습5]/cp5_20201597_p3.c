#include <stdio.h>

void pascal(int level, long long int tri[][100]);
int main(void){
	int n,i,j;
	long long int tri[100][100]={0,};
	scanf("%d",&n);
	
	pascal(n,tri);
	for (i=0;i<n;i++){
		for (j=0;j<i+1;j++){
			printf("%lld ",*(*(tri+i)+j));
		}
		printf("\n");
	}
	return 0;
}
void pascal(int level, long long int tri[][100]){
	int i,j;
	for (i=0;i<level;i++){
		*(*(tri+i)+0) = 1;
		*(*(tri+i)+i) = 1; 
	}
	
	if (level > 2){
		for (i=2;i<level;i++){
			for (j=1;j<i;j++){
				*(*(tri+i)+j) = *(*(tri+i-1)+j) + *(*(tri+i-1)+j-1);
			}
		}
	}
}
