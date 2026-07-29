#include <stdio.h>

int bitXor( int a, int b){

  int c = ~ ( a & b );
  int d = ~ ( ~a & ~b );

  return c & d;
}

int main ( ){

  int a = 2;
  int b = 7;

  printf("%d\n", bitXor(a, b));

  return 0;
}
