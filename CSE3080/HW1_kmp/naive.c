#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000000

char L_s[MAX], L_p[MAX];
int ans[MAX];

int main(){
	FILE* f_s = fopen("string.txt", "r");
	FILE* f_p = fopen("pattern.txt", "r");

	if(!f_s){
		printf("The string file does not exist.\n");
		return 0;
	}
	if(!f_p){
		printf("The pattern file does not exist.\n");
		return 0;
	}
	
	fgets(L_s, MAX, f_s); fgets(L_p, MAX, f_p);
	int len_s,len_p;
	len_s = strlen(L_s);
	len_p = strlen(L_p);

	int match_cnt = 0;
	int i,j;
	int flag;
	for (i=0;i<len_s-len_p+1;i++){
		flag = 1;
		for (j=0;j<len_p;j++){
			if (L_s[i+j]!=L_p[j]){
				flag=0;
				break;
			}
		}
		if (flag){
			ans[match_cnt] = i;
			match_cnt+=1;
		}
	}
	
	FILE* f_w = fopen("result_naive.txt", "w");
		
	fprintf(f_w,"%d",match_cnt);
	fprintf(f_w, "\n");
	
	for(i = 0; i < match_cnt; i++){
		fprintf(f_w, "%d ", ans[i]);		
	}
	fprintf(f_w, "\n");
	printf("Program complete. Result saved to result_naive.txt\n");
	
	return 0;
}



