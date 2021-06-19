/* made by 20201597 dongjunshin*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **name;

char check[6];

int main(){

    int n;
    scanf("%d",&n);
    
    name = (char**)malloc(sizeof(char*)*(n+1));
    for (int i=0;i<n+1;i++){
        name[i] = (char*)malloc(sizeof(char)*21);
    }
    
    for (int i=0;i<n;i++){
        scanf("%s %s",name[i],check);
        if(check[0]=='l'){
            for (int j=0;j<i;j++){
                if (strcmp(name[j],name[i])==0){
                    name[j][0]='0';
                    name[i][0]='0';
                }                
            }
        }
    }
    char tmp[21];
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1;j++){
            if (strcmp(name[j],name[j+1])==1){
                
                strcpy(tmp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],tmp);
            }
        }
    }
    
    for (int i=0;i<n;i++){
        if (name[i][0]!='0'){
            printf("%s\n",name[i]);
        }
    }
    return 0;
}
