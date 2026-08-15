#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printInt(void *arr, int L, int R, int size){
  for(int i = L; i < R; i++){
    int value = *((int*) ((char*)arr + i * size));
    printf("%d ", value);
  }
  printf("\n");
}

//what is this can you read this comment i am able to read this comment and this is pretty readabel can yp do anything else
void generate_random(void *arr,int L, int R, int size){
  for(int i = L; i < R; i++){
    int value = rand() / 10000;

    char *position = ((char*)arr + i * size);
    memcpy(position, &value, size);
  }

}

int intComparator(void *i, void *j){
  int a = *((int *) i);
  int b = *((int *) j);

  if(a == b) return 0;
  if(a < b) return -1;

  return 1;
}

struct Student
{
  int roll_no;
  char *name;
  float marks;
};

int studentComp(void *i, void *j){
  struct Student s1 = *(( struct Student *) i);
  struct Student s2 = *(( struct Student *) j);

  if(s1.marks < s2.marks ) return -1;
  else if (s1.marks == s2.marks) return 0;
  return 1;
}

void swap(void *arr, int a, int b, int size){
  char *temp = (char*) malloc(size);
  char *i = (char*)arr + (a*size);
  char *j = (char*)arr + (b*size);
  memcpy(temp, i, size);
  memcpy(i, j, size);
  memcpy(j, temp, size);

  free(temp);
}

void sink(void *arr, int L, int R, int (*cmp)(void*, void*), int size){
  if(L >= R)return ;

  int leftChildPosition = (L * 2 + 1);
  int rightChildPosition = (L * 2 + 2);
  int maxPosition = L;
  
  void *max = (char*)arr + (maxPosition * size);


  if(leftChildPosition <= R ){
    void *leftChild = (char*)arr + (leftChildPosition * size);
    if(cmp(max, leftChild) < 0){
      maxPosition = leftChildPosition;
      max = leftChild;
    }
  }

  if(rightChildPosition <= R ){
    void *rightChild = (char*)arr + (rightChildPosition * size);
    if(cmp(max, rightChild) < 0){
      maxPosition = rightChildPosition;
      max = rightChild;
    }
  }

  if(maxPosition != L){
    swap(arr, maxPosition, L, size);
    sink(arr, maxPosition, R, cmp, size);
  }
}

void heapsort(void *arr, int L, int R, int (*cmp) (void*, void*), int size){
  for(int i = R / 2; i >= L; i--){
      sink(arr, i, R, cmp, size);
    }

    for(int i = R; i > L;  i--){
      swap(arr, L, i, size);

      sink(arr, L, i - 1, cmp, size);
    }

}


int main (){
  int n;
  printf("enter the size of Array: ");
  scanf("%d", &n);
  int a [n];

  generate_random(a, 0, n, sizeof(int));
  printInt(a, 0, n, sizeof(int));

  heapsort(a, 0, n - 1, intComparator, sizeof(int));
  printInt(a, 0, n, sizeof(int));

  int RollNo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  char *names[] = {"Ritish", "Hash", "Hardik", "Sarthi", "Rutvi", "Parth", "Ritesh", "Ridhimma", "Himanshu"};
  float Marks[] = {95, 70.5, 85.5, 75.6, 95.5, 92, 80.6, 90.7, 85.5};
  struct Student data[9];

  for(int i = 0; i < 9; i++){
    data[i].name = names[i];
    data[i].roll_no = RollNo[i];
    data[i].marks = Marks[i];
  }

  heapsort(data, 0, 8, studentComp, sizeof(struct Student));

  for(int i = 0; i < 9; i++){
    printf("student name : %s ,",data[i].name);
    printf("student Roll_no : %d ,",data[i].roll_no);
    printf("student Marks : %f \n",data[i].marks);
  }

  return 0;
}