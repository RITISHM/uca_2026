#include <stdio.h>
#include <string.h>

int main () {
  
  char str[100];

  fgets(str, sizeof(str), stdin);

  char *tokens = strtok(str,",");
  
  while(tokens != NULL) {

    printf("%s\n",tokens);
    tokens= strtok(NULL, ",");

  }

  return 0;
}