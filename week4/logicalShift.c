#include <stdio.h> 

int logicalShift(int x, int n){
  int mask = 1 << 31;
  mask = ~(((mask) >> n) << 1);

  x = x >> n;



  return x & mask;
}


int main (){
  int x = 7 , n = 1 ;

  printf("%d\n", logicalShift(x, n));

  
  return 0;

}
