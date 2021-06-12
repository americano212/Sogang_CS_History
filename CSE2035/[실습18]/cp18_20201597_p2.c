#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nptr;

typedef struct node{
	char data;
	nptr link;
}NODE;

nptr head = NULL;

void InsertNodeAtFront(char a) {
   NODE* arr = (NODE*)malloc(sizeof(NODE));
   
   arr->data = a;
   arr->link = head;
   head = arr;
}


void InsertNodeAtBack(char b) {
   NODE* arr = (NODE*)malloc(sizeof(NODE));
   
   arr->data = b;
   arr->link = NULL;

   if (head == NULL) head = arr;
   else {
		NODE* x = head;
		while (x->link != NULL) {
			x = x->link;
		}
		x->link = arr;
	}
}

void PrintList() {
	nptr arr = head;
	while (1) {
		if (arr==NULL) break;
		printf("%c", arr->data);
		arr = arr->link;
	}
	printf("\n");
}


int main(){
	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');
	PrintList();
	return 0;
}
