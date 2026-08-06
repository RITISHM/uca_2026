#include <stdio.h>

int sign( int a ) {
  int b = a >> 31;

  return !!(a) | b;
}

int main() {
  printf("%d\n", sign( 0 )); //Output : 0
  printf("%d\n", sign( 124 )); //Output : 1
  printf("%d\n", sign( -123 )); //Output : -1

  return 0;

}
