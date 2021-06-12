#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node{
   int data;
   struct node* link;
} NODE;

void Insert(NODE** head,int n){
	NODE* arr = malloc(sizeof(NODE));
	arr->data = n;
	arr->link = NULL;

	if (*head == NULL) {
		*head = arr;
	}
	else {
		NODE* x = *head;
		while (1) {
			if (x->link == NULL) break;
			x = x->link;
		}
		x->link = arr;
	}
}

void Delete(NODE** head){
	nptr x = *head;
	*head = x->link;
	free(x);
}

void PrintAll(NODE* head) {
	nptr x = head;
	if (x->link==NULL){
		printf("%d\n",x->data);
		printf("Empty");
		return;
	}
	
	else{
		while(1){
			printf("%d  ",x->data);
			x = x->link;
			if (x->link == NULL) {
				printf("%d  ",x->data);
				break;
			}
		}
	}
	
	printf("\n");
}

int main(){
	int A[10] = {3,9,8,2,5,10,7,1,4,6};
	nptr head = NULL;
	int i;
	for (i=0;i<10;i++){
		Insert(&head,A[i]);
	}
	PrintAll(head);
	for (i=0;i<9;i++){
		Delete(&head);
		PrintAll(head);
	}
	free(head);
	return 0;
}
