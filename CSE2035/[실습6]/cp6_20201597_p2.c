#include <stdio.h>
#include <stdlib.h>

int MAX(int a,int b){
	int temp;
	temp = (a<b) ? b : a;
	return temp;
}

int main(void){
	int n,m,i,*ans,max,temp;
	char *arr1,*arr2;
	
	scanf("%d %d",&n,&m);
	max = MAX(n,m);

	arr1 = (char *)malloc((n)*sizeof(char));
	arr2 = (char *)malloc((m)*sizeof(char));
	ans = (int *)malloc((max+1)*sizeof(int));	
	
	scanf("%s",arr1);
	scanf("%s",arr2);
	ans[0] = arr1[n-1]-48 + arr2[m-1] -48;
	for (i=1;i<max+1;i++){
		temp = 0;
		if (i<n){
			temp = temp + arr1[n-i-1]-48;
		}
		if (i<m){
			temp = temp + arr2[m-i-1]-48;
		}
		if (ans[i-1]>=10){
			ans[i] = temp+1;
			ans[i-1] -= 10;
		}
		else{
			ans[i] = temp;
		}
	}
	if (ans[max]==0){
		for (i=max-1;i>=0;i--){
			printf("%d",ans[i]);
		}
	}
	else{
		for (i=max;i>=0;i--){
			printf("%d",ans[i]);
		}
	}
	printf("\n");
	return 0;
}

