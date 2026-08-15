#include <stdio.h>
int main(){
  int n = 0;
  printf("Enter the size of array : ");
  scanf("%d", &n);
  
  int arr[n];
  for(int i = 0; i < n; i++){
    printf("enter the element %d : ", i);
    scanf("%d", &arr[i]);
  }

  int ans = 0;
  for(int i = 0; i < 32; i++){
    int  count = 0;

    for(int j = 0; j < n; j++){
      if(((arr[j]>> i) & 1) == 1) count++;
    }

    if(count % 3 == 1){
      ans = ans | (1 << i);
    }

  }
  printf("ans : %d", ans);
  return 0;
}