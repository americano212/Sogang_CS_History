/* made by 20201597 dongjunshin*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **arr;
int w,h;
void dfs(int x,int y){
    arr[x][y] = 0;
    for (int i=0;i<4;i++){
        if (x!=0){
            if (arr[x-1][y]==1)
                dfs(x-1,y);
        }
        if (x!=h-1){
            if (arr[x+1][y]==1)
                dfs(x+1,y);
        }
        if (y!=0){
            if (arr[x][y-1]==1)
                dfs(x,y-1);
        }
        if (y!=w-1){
            if (arr[x][y+1]==1)
                dfs(x,y+1);
        }
        if (x!=0 && y!=0){
            if (arr[x-1][y-1]){
                dfs(x-1,y-1);
            }
        }
        if (x!=0 && y!=w-1){
            if (arr[x-1][y+1]){
                dfs(x-1,y+1);
            }
        }
        if (x!=h-1 && y!=0){
            if (arr[x+1][y-1]){
                dfs(x+1,y-1);
            }
        }
        if (x!=h-1 && y!=w-1){
            if (arr[x+1][y+1]){
                dfs(x+1,y+1);
            }
        }

    }
}

int main(){
    while(1){
        scanf("%d %d",&w,&h);
        if (w==0 && h==0){
            return 0;
        }
        arr = (int**)malloc(sizeof(int*)*(h+1));
        for (int i=0;i<h+1;i++){
            arr[i] = (int*)malloc(sizeof(int)*w);
        }
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        int cnt = 0; 
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                if(arr[i][j]==1){
                    dfs(i,j);
                    cnt+=1;
                }
            }
        }
        printf("%d\n",cnt);
        
        for (int i=0;i<h+1;i++){
            free(arr[i]);
        }
        free(arr);
    }
}
