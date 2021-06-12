#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char dept_name[25];
	int dept_no;
}dept;

enum Gender { Male = 0, Female };

typedef struct {
	int employee_id;
	char name[25];
	enum Gender gender;
	dept department;
	double salary;
}employee_data;

int search(employee_data* e, int num, int keyword) {
	int i;
	for (i = 0; i < num; i++){
		if (e[i].employee_id == keyword){
			return i;
		} 
	} 
	return -1;
}
employee_data update(employee_data e, int n);

int main(void) {
	FILE* fp = fopen("16_input.txt", "r");
	employee_data* arr;
	int n, id, x, op;
	char tmp;
	char * ptr;
	fscanf(fp, "%d", &n);
	arr = (employee_data*)malloc(sizeof(employee_data) * n);
	ptr = (char*)malloc(sizeof(char) * 10);
	int i;
	for (i = 0; i < 26; i++) {
		fscanf(fp, "%d", &arr[i].employee_id); 
		for (i = 0; i < 3; i++) {
			fscanf(fp, "%c", &tmp);
		}
		fscanf(fp, "%[^/]s", ptr); 
		for (i = 0; i < 2; i++) {
			fscanf(fp, "%c", &tmp);
		}
		ptr[strlen(ptr) - 1] = '\0'; 
		strcpy(arr[i].name, ptr);
		fscanf(fp, "%[^ ]s", ptr); 
		for (i = 0; i < 3; i++) {
			fscanf(fp, "%c", &tmp);
		}
		if (ptr[0] == 'M'){
			arr[i].gender = Male;
		} 
		else arr[i].gender = Female;
		fscanf(fp, "%[^/]s", ptr); 
		for (i = 0; i < 2; i++){
			fscanf(fp, "%c", &tmp);
		} 
		ptr[strlen(ptr) - 1] = '\0'; 
		strcpy(arr[i].department.dept_name, ptr);
		fscanf(fp, "%d", &arr[i].department.dept_no); 
		for (i = 0; i < 2; i++){
			fscanf(fp, "%c", &tmp);
		} 
		fscanf(fp, "%lf", &arr[i].salary);
	}
	while (1) {
		printf("Employee ID : ");
		scanf("%d", &id);
		x = search(arr, n, id);
		if (x != -1) {
			printf("------Employee Data------\n");
			if (arr[x].gender == 0){
				strcpy(ptr, "Male");
			} 
			else strcpy(ptr, "Female");
			printf("%d / %s / %s / %s / %d / %0.2lf\n", arr[x].employee_id, arr[x].name, ptr, arr[x].department.dept_name, arr[x].department.dept_no, arr[x].salary);
			printf("------Update Information------\n");
			printf("Input the department Number : ");
			scanf("%d", &op);
			switch (op) {
			case 1: strcpy(ptr, "FINANCE"); arr[x].department.dept_no = 1; break;
			case 2: strcpy(ptr, "SALES"); arr[x].department.dept_no = 2; break;
			case 3: strcpy(ptr, "RESEARCH"), arr[x].department.dept_no = 3; break;
			case 4: strcpy(ptr, "PLANNING"), arr[x].department.dept_no = 4; break;
			}
			strcpy(arr[x].department.dept_name, ptr);
			if (arr[x].gender == 0){
				strcpy(ptr, "Male");
			} 
			else strcpy(ptr, "Female");
			printf("------Updated employee data------\n");
			printf("%d / %s / %s / %s / %d / %0.2lf\n", arr[x].employee_id, arr[x].name, ptr, arr[x].department.dept_name, arr[x].department.dept_no, arr[x].salary);
		}
		else printf("No employee\n");

		printf("Continue? (y/n) : ");
		scanf("%c", &tmp); 
		scanf("%c", &tmp);
		if (tmp == 'n') break;
	}
	return 0;
}
