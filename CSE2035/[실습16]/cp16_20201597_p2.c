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
	printf("�α��� ���α׷�\n");
	char inp_id[50];
	char inp_pw[50];
	int t_id = 0;
	int i,index=6;
	while(login_check<3){
		t_id = 0,index=6;
		printf("���̵� : ");
		scanf("%s",inp_id);
		printf("�н����� : ");
		scanf("%s",inp_pw);
		for (i=0;i<5;i++){
			if (strcmp(inp_id,cus[i].id)==0 && strcmp(inp_pw,cus[i].pw)==0){
				t_id = 1;
				index = i;
			}
		}
		if (t_id==1){
			printf("====================\n");
			printf("ȸ����ȣ : %d\n",cus[index].number);
			printf("���̵�: %s\n",cus[index].id);
			printf("�н����� : %s\n",cus[index].pw);
			printf("�̸�  : %s\n",cus[index].name);
			printf("�ּ�  : %s\n",cus[index].address);
			break;
		}
		else{
			printf("��ġ�ϴ� ȸ���� �����ϴ�.\n");
		}
		
		login_check++;
	}
	return 0;
}
