#include<stdio.h>
void get_div(int arr[],int tmp){
    while(1){
        if (tmp==0) break;
        arr[tmp%10]+=1;
        tmp/=10;
    }
}
