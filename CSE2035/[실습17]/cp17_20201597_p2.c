#include <stdio.h>
#include <stdlib.h>

typedef struct _SUBJECT_ {
   char number[8];
   int credit;
   double grade;
}subject;

typedef struct _STUDENT_ {
   int idx
   int number_of_course;
   subject* courses;
} student;

double calcCGPA(student s) {
   double Sum = 0;
   double div = 0;
   int i;
   for (i = 0; i < s.number_of_course; i++) {
    Sum += s.courses[i].grade * s.courses[i].credit; 
	div += s.courses[i].credit; 
	}
   return Sum / div;
}

int main(void) {
   int t;
   student* arr;
   scanf("%d", &t);
   arr = (student*)malloc(sizeof(student) * t);
   int i,j;
   
   for (i = 0; i < t; i++) {
      scanf("%d %d", &arr[i].idx, &arr[i].number_of_course);
      arr[i].courses = (subject*)malloc(sizeof(subject) * arr[i].number_of_course);
      for (j = 0; j < arr[i].number_of_course; j++) {
         scanf("%[^ ]s", arr[i].courses[j].number);
         scanf("%d", &arr[i].courses[j].credit);
         scanf("%lf", &arr[i].courses[j].grade);
      }
   }
   printf("=============\n");
   for (i = 0; i < t; i++)
      printf("%d / %0.6lf\n", arr[i].idx, calcCGPA(arr[i]));
   return 0;
}
