#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000000

char L_s[MAX], L_p[MAX];
int ans[MAX];
int T[MAX];


int main(void){
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

	int start = 0;
	int idx = -1;
	T[0] = -1;
	while(start<len_p) {
		if(L_p[start]==L_p[idx] || idx == -1){
			start+=1;
			idx+=1;
			T[start] = idx;
		}
		else{
			idx = T[idx];
		}
	}

	int match_cnt = 0;
	int i=0;
	int j=0;
	while(i < len_s){
		while(j >= 0 && L_s[i] != L_p[j]){
			j = T[j];
		}
		i+=1;
		j+=1;
		if(j==len_p){
			ans[match_cnt] = i-j;
			match_cnt++;
		}
	}

	FILE* f_w = fopen("result_kmp.txt", "w");

	fprintf(f_w,"%d",match_cnt);
	fprintf(f_w, "\n");

	for(i = 0; i < match_cnt; i++){
		fprintf(f_w, "%d ", ans[i]);
	}
	fprintf(f_w, "\n");
	printf("Program complete. Result saved to result_kmp.txt\n");
	return 0;
}
