#include <stdio.h>

int sign( int a ) {
  int b = a >> 31;

  return b | !!(a);
}

int main() {
  printf("%d\n", sign( 0 ));
  printf("%d\n", sign( 124 ));
  printf("%d\n", sign( -123 ));

  return 0;

}
