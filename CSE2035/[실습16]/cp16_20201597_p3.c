#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	int level;
	char type1[30];
	char type2[30];
	char sk1[20];
	char sk2[20];
	char sk3[20];
	char sk4[20];
} dex;

typedef struct {
	int inx;
	char name[10];
	char region[10];
	dex poke[6];
}user;

int main(void) {
	char t;
	FILE* fp = fopen("user.txt", "r");
	char* temp = (char*)malloc(sizeof(char) * 1000);
	user* arr = (user*)malloc(sizeof(user) * 1000);
	int  n = 0;
	int i;
	int idx, k;
	int cnt = 0;
	while (fscanf(fp, "%c", &t) != EOF) {
		if (!(t >= 'a' && t <= 'z') && !(t >= 'A' && t <= 'Z')){
			continue;
		} 
		temp[0] = t; fscanf(fp, "%[^\t]s", temp + 1);
		for (i = 0; i < n; i++){
			if (strcmp(arr[i].name, temp) == 0) break;
		}	
		if (i == n) {
			i = n++; arr[i].inx = 0;
		}
		strcpy(arr[i].name, temp); 
		arr[i].name[strlen(temp)] = '\0';
		idx = arr[i].inx;
		fscanf(fp, "%c", &t);
		fscanf(fp, "%[^\t]s", &arr[i].region); 
		fscanf(fp, "%c", &t);
		fscanf(fp, "%d", &arr[i].poke[idx].num); 
		fscanf(fp, "%c", &t);
		fscanf(fp, "%[^\t]s", &arr[i].poke[idx].name); 
		fscanf(fp, "%c", &t);
		fscanf(fp, "%d", &arr[i].poke[idx].level); 
		fscanf(fp, "%c", &t);
		fscanf(fp, "%[^\t]s", temp); 
		fscanf(fp, "%c", &t);
		for (k = 0; k < strlen(temp); k++){
			if (temp[k] == ',') break;
		}
		if (k == strlen(temp)) {
			strcpy(arr[i].poke[idx].type1, temp); arr[i].poke[idx].type1[strlen(temp)] = '\0'; arr[i].poke[idx].type2[0] = '\0';
		}
		else {
			strncpy(arr[i].poke[idx].type1, temp, k); arr[i].poke[idx].type1[k] = '\0';
			strncpy(arr[i].poke[idx].type2, temp + k + 1, strlen(temp) - (k - 1)); arr[i].poke[idx].type1[strlen(temp)] = '\0';
		}

		fscanf(fp, "%[^,]s", arr[i].poke[idx].sk1); fscanf(fp, "%c", &t);
		fscanf(fp, "%[^,]s", arr[i].poke[idx].sk2); fscanf(fp, "%c", &t);
		fscanf(fp, "%[^,]s", arr[i].poke[idx].sk3); fscanf(fp, "%c", &t);
		fscanf(fp, "%[^\n]s", arr[i].poke[idx].sk4); fscanf(fp, "%c", &t);
		arr[i].inx++;
	}
	printf("Number of Users = %d\n\n", n);
	int i,j;
	for (i = 0; i < n; i++) {
		printf("[Name] %s(%s)\n", arr[i].name, arr[i].region);
		printf(" [Pokemon]\n");
		for (j = 0; j < arr[i].inx; j++) {
			printf("  [Name]%s(%d)\n", arr[i].poke[j].name, arr[i].poke[j].num);
			printf("  [level]%d\n", arr[i].poke[j].level);
			if (arr[i].poke[j].type2[0] == '\0')
				printf("  [Type]%s\n", arr[i].poke[j].type1);
			else {
				printf("  [Type1]%s\n", arr[i].poke[j].type1);
				printf("  [Type2]%s\n", arr[i].poke[j].type2);
			}
			printf("  [Skill1]%s\n", arr[i].poke[j].sk1);
			printf("  [Skill2]%s\n", arr[i].poke[j].sk2);
			printf("  [Skill3]%s\n", arr[i].poke[j].sk3);
			printf("  [Skill4]%s\n", arr[i].poke[j].sk4);
			printf("\n");
		}
	}
	return 0;
}
