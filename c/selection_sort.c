#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void generator(int arr[], int n){
	for(int i=0;i<n;i++){
		arr[i]=rand();
	}
}

void ascendingGenerator(int arr[], int n){
	for(int i=0;i<n;i++){
		arr[i]=i;
	}
}

void descendingGenerator(int arr[], int n){
	for(int i=n-1;i>=0;i--){
		arr[i]=n-i-1;
	}
}

int main(){
	srand(time(0));
	int size=8000;
	for(int i=0;i<8;i++){
		int arr[size];
		generator(arr,size);
		int asc[size];
		int desc[size];
		ascendingGenerator(asc,size);
		descendingGenerator(desc,size);
		clock_t start=clock();
		sort(arr,size);
		clock_t end=clock();
		double normalTime = (double)(end-start)*1000/CLOCKS_PER_SEC;
		start = clock();
		sort(asc,size);
		end = clock();
		double ascTime = (double)(end-start)*1000/CLOCKS_PER_SEC;
		start = clock();
		sort(desc,size);
		end = clock();
		double descTime = (double)(end-start)*1000/CLOCKS_PER_SEC;
		printf("%f %f %f\n", normalTime, ascTime, descTime);
		size+=4000;

	}
	return 0;
}


