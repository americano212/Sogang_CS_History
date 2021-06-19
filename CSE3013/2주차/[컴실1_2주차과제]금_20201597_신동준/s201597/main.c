#include "Header.h"
#include<stdio.h>

int main(){
	int t,i;
	int arr[11] = {0,};
	scanf("%d",&t);
	for(i=0;i<t;i++){
		int j;
	    for(j=0;j<10;j++){
	        arr[j]=0;
	    }
		double n;
		scanf("%lf",&n);
		for(j=1;j<n+1;j++){
			get_div(arr,j);
		}
        prt_result(arr);
	}
    return 0;
}
