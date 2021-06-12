#include <stdio.h>
#include <string.h>
void split_string(char *str, char *string_1, char *string_2) {
   int len;
   len = strlen(str);
   strcpy(string_1, str);
   string_1[len / 2] = '\0';
   int i;
   for (i = 0; i <= len + 1; i++) {
      string_2[i] = str[i+len/2];
   }
}


int main() {
   char string_1[26];
   char string_2[26];
   char get_s[51];
   printf("input str : ");
   gets(get_s);
   split_string(get_s, string_1, string_2);
   printf("[%s] -> [%s] [%s]\n",get_s,string_1,string_2);
   return 0;
}
