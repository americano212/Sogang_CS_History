#include <stdio.h>
int n,m;
int arr[21];
int i;
int sum, counting;
void SoS(int x);
int main(void){
	
	scanf("%d %d",&n,&m);

	
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	SoS(0);
	printf("The number of subsets is %d\n",counting);
	return 0;
}

void SoS(int x){
	if(x == n){
		return;
	}
	if(sum+arr[x] == m){
		counting += 1;
	}
	SoS(x+1);
	sum += arr[x];
	SoS(x+1);
	sum -= arr[x];
}
