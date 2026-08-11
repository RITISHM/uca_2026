#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global size kept ONLY for the priority queue operations (insert/del_max)
int size = 0;

int sizeOf(){
  return size;
}

void swap(int heap[], int parent, int index){
  int temp = heap[parent];
  heap[parent] = heap[index];
  heap[index] = temp;
}

int get_max(int heap[]){
  if (size == 0) {
    printf("heap is empty\n");
    return -1;
  }
  return heap[0];
}

void swim(int heap[], int index){
  if (index == 0) return;
  // Fixed 0-indexed math
  int parent = (index - 1) / 2; 
  if(heap[parent] < heap[index]){
    swap(heap, parent, index);
    swim(heap, parent);
  }
}

// Updated to take a dynamic 'current_size' parameter
void sink(int heap[], int index, int current_size){
  if (index >= current_size) return;
  
  int L = 2 * index + 1;
  int R = 2 * index + 2;
  int max = index;
  
  if (L < current_size && heap[L] > heap[max]){
    max = L;
  }
  if (R < current_size && heap[R] > heap[max]){
    max = R;
  }
  if (max != index){
    swap(heap, index, max);
    sink(heap, max, current_size);
  }
}

void insert(int heap[] , int key){
  heap[size] = key;
  swim(heap, size);
  size++;
}

int del_max(int heap[]){
  if (sizeOf() == 0){
    printf("underflow - i dont have any element\n");
    return -1;
  }

  int res = get_max(heap);
  swap(heap, 0, size - 1);
  size--;
  sink(heap, 0, size); // Pass the global size here

  return res;
}

void generate_random(int random[], int n){
  for (int i = 0; i < n; i++){
    random[i] = rand() % 1000;
  }
}

// Completely self-contained Heapsort! No globals needed.
void heapsort(int heap[], int n){
  // 1. Build the max heap
  for (int i = n / 2 - 1; i >= 0; i--){
    sink(heap, i, n);
  }
  
  // 2. Extract max elements one by one
  for (int i = n - 1; i > 0; i--){
    swap(heap, 0, i);
    // Shrink the boundary of the heap by 1 each loop iteration
    sink(heap, 0, i); 
  }
}

void ascendingGenerator(int arr[], int n){
  for(int i = 0; i < n; i++){
    arr[i] = i;
  }
}

void descendingGenerator(int arr[], int n){
  for(int i = n - 1; i >= 0; i--){
    arr[i] = n - i - 1;
  }
}

int main(){
  // Increased starting size so clock() can actually measure the time
  int n = 100000; 
  
  for(int i = 0; i < 4; i++){
    int arr[n];
    generate_random(arr, n);
    
    int asc[n];
    ascendingGenerator(asc, n);
    
    int desc[n];
    descendingGenerator(desc, n);

    clock_t start = clock();
    heapsort(arr, n);
    clock_t end = clock();
    double normalTime = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    heapsort(asc, n);
    end = clock();
    double ascTime = (double)(end - start) / CLOCKS_PER_SEC;
    
    start = clock();
    heapsort(desc, n);
    end = clock();
    double descTime = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("No of elements: %d\n", n);
    printf("Random: %f sec | Ascending: %f sec | Descending: %f sec\n", normalTime, ascTime, descTime);
    printf("------------------------------------------------------\n");
    
    n += 100000;    
  }

  return 0;
}