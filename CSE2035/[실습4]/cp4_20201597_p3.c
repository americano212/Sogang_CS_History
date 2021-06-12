#include <stdio.h>

void count(int board[][100], int n, int m);

int main(void){
	int n,m,inp[100][100],i,j;
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			scanf("%d",(*(inp+i)+j));
		}
	}
	count(inp, n, m);
	return 0;
}

void count(int board[][100], int n, int m){
	int i,j,check[100][100]={0,},counting = 0;
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (*(*(board+i)+j)== 0){
				if (*(*(check+i)+j)== 0 && j+1<m && *(*(check+i)+j+1)==0){
					counting += 1;
					*(*(check+i)+j) = counting;
					*(*(check+i)+j+1) = counting;
					
				}
				else if (*(*(check+i)+j) ==0 && i+1<n && *(*(check+i+1)+j)==0){
					
					counting += 1;
					*(*(check+i)+j) = counting;
					*(*(check+i+1)+j) = counting;
				}
				
			}
			else{
				if (*(*(check+i)+j) ==0 && i+1<n && *(*(check+i+1)+j)==0){
					counting += 1;
					*(*(check+i)+j) = counting;
					*(*(check+i+1)+j) = counting;
					
				}
				else if (*(*(check+i)+j) == 0 && j+1<m && *(*(check+i)+j+1)==0){
					counting += 1;
					*(*(check+i)+j) = counting;
					*(*(check+i)+j+1) = counting;
				}
			}
		}
	}
	printf("%d\n",counting);
}
