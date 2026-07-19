#include <stdio.h>
#include <string.h>
int main() {

  char str[100];

  fgets(str, sizeof(str), stdin);
  printf("orignal string is : %s\n", str);

  int length = strlen(str);

  for (int i = 0, j = length - 1; i < length / 2; i++){

    char temp = str [i];
    str[i] = str[j];
    str[j--] = temp;

  }

  printf("reversed string is : %s", str);

  return 0;
}