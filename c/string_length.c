#include <stdio.h>

int main() {

  char str[100];

  fgets(str, sizeof(str), stdin);

  int length = 0;
  
  while (str[length] != '\0'){
    length++;
  }

  printf("length of the \"%s\" is : %d", str, length);

  return 0;
}