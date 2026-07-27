class ReversePair {
  
  static int bruteForce(int [] arr){
    
    int reversePairsCount = 0;
    
    for (int i =0; i < arr.length; i++){
      for (int j = i + 1; j < arr.length; j++){
        
        if (arr[i] > 2 * arr[j]){
          reversePairsCount++;
        }
        
      }
    }
    
    return  reversePairsCount;
  }
  
    static int mergeSort(int arr [], int low, int high){

      if(low >= high) return 0;

      int mid = (high - low)/2 + low;

      int count = 0;
      
      count += mergeSort(arr, low, mid);
      count += mergeSort(arr, mid + 1, high);

      int lp = low, rp = mid + 1;

      while( lp <= mid && rp <= high){
          if ( arr[lp] > 2 * arr[rp]){
              count += mid - lp + 1;
              rp++;
          }
          else{
              lp++;
          }
      }
      
      merge(arr, low, mid, high);
      return count;

  }

  static void merge(int [] arr, int low, int mid, int high){
      int lp = low;
      int rp = mid + 1; 
      int [] sortedArray = new int [high - low + 1];
      int sp = 0;

      while (lp <= mid && rp <= high){
          if (arr[lp] > arr[rp]){
              sortedArray[ sp++ ] = arr[ rp++ ];
          }

          else{
              sortedArray[ sp++ ] = arr[ lp++ ];
          }
      }

      while(lp <= mid){
          sortedArray[ sp++ ] = arr[ lp++ ];
      }

      while(rp <= high){
          sortedArray[ sp++ ] = arr[ rp ++ ];
      }

      sp = 0;
      while ( low <= high){
          arr[low++] = sortedArray[sp++];
      }

  }


  
  public static void main(String[] args) {
    int[] arr = {1, 3, 2, 3, 1};

    //int reversePairsCount = bruteForce(arr);
    int reversePairsCount = mergeSort(arr, 0, arr.length - 1);

    System.out.println("Number of reverse pairs: " + reversePairsCount);
  }


}