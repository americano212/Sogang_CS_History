#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1001];

int big(int a,int b){
    if(a>=b){
        return a;
    }
    if (a<b){
        return b;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&dp[i]);
    }
    int max=0;
    for(int i=1;i<n;i++){
        max = dp[i];
        for (int j=0;j<(i+1)/2;j++){
            max = big(max, dp[j]+dp[i-1-j]);
        }
        dp[i] = max;
        
    }
    printf("%d\n",dp[n-1]);
}
