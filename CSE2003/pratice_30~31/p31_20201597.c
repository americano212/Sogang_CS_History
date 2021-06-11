#include <stdio.h>

int main(void){
	int gtxt_1,gtxt_2;
	int N=1,i=0,j=0,flag =1;
	int arr_1[100],arr_2[100];
	int state_1,state_2,state_3;
	int flag_1 = 0, flag_2 = 0,compare = 0;
	char f_name1[21], f_name2[21];
	int check = 0;
	printf("Input first file name: ");
	scanf("%s",f_name1);
	printf("Input second file name: ");
	scanf("%s",f_name2);
	FILE* txt_1 = fopen(f_name1,"r");
	FILE* txt_2 = fopen(f_name2,"r");
	FILE* op = fopen("output","w");
	if (txt_1 == NULL || txt_2 == NULL){
		printf("file open error\n");
		return 1;
	}
	do{
		gtxt_1 = fgetc(txt_1);
		gtxt_2 = fgetc(txt_2);
		if (gtxt_1 == -1) break;
		if (gtxt_2 == -1) break;		
		if (gtxt_1 != 32 && gtxt_1 != 13){
			arr_1[i] = gtxt_1;
			i+=1;
		}
		else if(gtxt_1 == 13){
			gtxt_1 = fgetc(txt_1);
			N-=1;
		}
		else{
			flag_1 +=1;
			check += 1;
		}
		if (gtxt_2 != 32 && gtxt_2 != 13){
			arr_2[j] = gtxt_2;
			j+=1;
		}
		else if(gtxt_2 == 13){
			gtxt_2 = fgetc(txt_2);
			N-=1;
		}
		else{
			flag_2 +=1;
			check += 1;
		}
		N+=1;
		if (check != 0){
			compare -= 1;
			check = 0;
		}
		if (arr_1[i-1] == arr_2[j-1]){
			compare += 1;
		}
	} while(gtxt_1 != EOF || gtxt_2 != EOF);
	if (i>j){
		flag += flag_1;
	}
	else{
		flag += flag_2;
	}
	fprintf(op,"Total character: %d\n",N-flag);
	fprintf(op,"Same character: %d\n",compare);
	fprintf(op,"%.3f%%\n",100*(float)(compare)/(float)(N-flag));
	state_1=fclose(txt_1);
	state_2=fclose(txt_2);
	state_3=fclose(op);
	if(state_1 != 0 || state_2 != 0 || state_3 != 0){
		printf("file close error\n");
		return 1;
	}
	
	return 0;
}

