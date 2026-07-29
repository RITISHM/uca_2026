#include <stdio.h>

int bitAnd(int a, int b){
  a = ~a;
  b = ~b;

  return ~(a | b);
}

int main (){
  int a = 5;
  int b = 6;
  
  printf("%d\n", bitAnd(a, b) );

  return 0;  
}
