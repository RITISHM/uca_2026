#include <stdio.h>

int getByte( int x, int n ) {
  x = x >> (n * 8);
  
  return 0xff & x;
}

int main() {
  printf("0x%X\n", getByte(0x12345678, 1));

  return 0;

}
