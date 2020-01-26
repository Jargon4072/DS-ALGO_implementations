#include<stdio.h>
char* getMerged(const char* str1, const char* str2) {
  char* str = malloc(strlen(str1)+strlen(str2)+1);
  int k=0,i;
  for(i=0;str1[i] !='\0' && str2[i] !='\0';i++) {
         str[k++] = str1[i];
         str[k++] = str2[i];
  }

  str[k]='\0';
  if (str1[i] != '\0') {
        strcpy(&str[k], &str1[i]);
  } else if (str2[i] != '\0') {
        strcpy(&str[k], &str2[i]);
  }
 return str;
}

int main(){
  char* str1="abc";
  char* str2="defz";
  char* res=getMerged(str1,str2);
  printf("%s",res);
  return 0;
}