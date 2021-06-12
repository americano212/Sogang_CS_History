#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int number;
	char id[50];
	char pw[50];
	char name[50];
	char address[200];
} customer;

int main(){
	FILE *fp = fopen("customer.txt", "r");
	char s[101];
	char* result;
	customer *cus;
	cus = (customer*)malloc(sizeof(customer)*6);
	int count = 0;
	fgets(s,100,fp);
	while(!feof(fp)){
		fgets(s,100,fp);
		result = strtok(s,",");
		cus[count].number=*result-48;
		result = strtok(NULL,",");
		strcpy(cus[count].id, result);
		result = strtok(NULL,",");
		strcpy(cus[count].pw, result);
		result = strtok(NULL,",");
		strcpy(cus[count].name, result);
		result = strtok(NULL,",");
		strcpy(cus[count].address, result);
		result = strtok(NULL,",");
		count+=1;
		if (count==5) break;
	}
	int login_check = 0;
	printf("로그인 프로그램\n");
	char inp_id[50];
	char inp_pw[50];
	int t_id = 0;
	int i,index=6;
	while(login_check<3){
		t_id = 0,index=6;
		printf("아이디 : ");
		scanf("%s",inp_id);
		printf("패스워드 : ");
		scanf("%s",inp_pw);
		for (i=0;i<5;i++){
			if (strcmp(inp_id,cus[i].id)==0 && strcmp(inp_pw,cus[i].pw)==0){
				t_id = 1;
				index = i;
			}
		}
		if (t_id==1){
			printf("====================\n");
			printf("회원번호 : %d\n",cus[index].number);
			printf("아이디: %s\n",cus[index].id);
			printf("패스워드 : %s\n",cus[index].pw);
			printf("이름  : %s\n",cus[index].name);
			printf("주소  : %s\n",cus[index].address);
			break;
		}
		else{
			printf("일치하는 회원이 없습니다.\n");
		}
		
		login_check++;
	}
	return 0;
}
