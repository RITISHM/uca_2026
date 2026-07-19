#include <stdio.h>
#include <string.h>

void url_encoded(char *str, int true_length){

  char url[strlen(str)];
  int j = 0;
  for (int i = 0; i < true_length; i++){

    if (str[i] == ' '){
      url[j++] = '%';
      url[j++] = '2';
      url[j++] = '0';
    }
    else url[j++] = str[i];

  }
  url[j]='\0';

  printf("Encorded Url : %s", url);

}

int main (){

  char str [100];
  int true_length;
  
  printf("enter the string");
  fgets(str, sizeof(str), stdin);
  
  printf("enter the true length");
  scanf("%d",&true_length);
  
  url_encoded(str, true_length);

  return 0;

}