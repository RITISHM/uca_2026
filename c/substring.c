#include <stdio.h>
#include <string.h>

int find_substring(char *str, char *substr){

  int len_substr = strlen(substr);
  int len_str = strlen(str);

  for (int i = 0; i < len_str - len_substr; i++){
    char sample [len_substr+1];
    
    for (int j = 0; j < len_substr; j++){
      sample[j] = str[i+j];
    }

    sample[len_substr] ='\0';

    if (strcmp(substr,sample ) == 0) {
      return i;
    }

  }

  return -1;
}

int main(){

  char str [100];
  char substr[100];

  fgets(str, sizeof(str), stdin);
  substr[strcspn(str, "\n")] = 0;

  fgets(substr, sizeof(substr), stdin);
  substr[strcspn(substr, "\n")] = 0;

  printf("%d", find_substring(str, substr));

  return 0;
}