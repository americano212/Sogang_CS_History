#include <stdio.h>  
int isDivisor(int m, int n);
int isPrime(int m);
int main(void){
	int N,j;
	printf("Input : ");
	scanf("%d",&N);
	for (j=2;j<=N;j++){
		if (isDivisor(j,N) && isPrime(j)){
			printf("%d\t",j);
		}
	}
	printf("\n");
	return 0;
}
int isDivisor(int m, int n){
	if (n%m==0){
		return 1;
	}
	else{
		return 0;
	}
}

int isPrime(int m){
	int i=2, j=m-1;
    if(m==1){
		return 0; 
	}
	
	while(1){
		if(i<=j){ 
			if(m%i==0){
				return 0; 
			}else{
				i++;
			}
		}else{
			return 1;
		}
	} 
}
