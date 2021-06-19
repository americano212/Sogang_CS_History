#include "Str.h"
#include <cstring>
#include <iostream>
using namespace std;
char end = '\0';
Str::Str (int leng) {
	str = new char[leng+1];
	for(int i = 0; i <= leng; i++) {
		str[i] = ' ';
	}
	str[leng] = end;
	len = leng;
}

Str::Str (char * neyong) {
	len = strlen(neyong);
	str = new char[len+1];
	strcpy(str, neyong);
}

Str::~Str () {
	delete[] str;
}

int Str::length (void) {
	return len;
}

char * Str::contents (void) {
	return str;
}

int Str::compare (class Str& a) {
	return strcmp(str, a.contents());
}

int Str::compare(char *a) {
	return strcmp(str, a);
}

void Str::operator=(char * a) {
	delete[] str;
	if(a == NULL) {
		len = 0;
		str = new char[0];
		str[0] = end;
	}
	else {
		len = strlen(a);
		str = new char[len+1];
		strcpy(str, a);
	}
}

void Str::operator=(class Str& a) {
	delete[] str;
	len = a.length();
	str = new char[len+1];
	strcpy(str, a.contents());
}
