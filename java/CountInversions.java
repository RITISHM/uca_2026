public class CountInversions {
      static int mergeSort(int arr [], int low, int high){

        if(low >= high) return 0;

        int mid = (high - low)/2 + low;

        int count = 0;
        
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);

        int lp = low, rp = mid + 1;

        while( lp <= mid && rp <= high){
            if ( arr[lp] > arr[rp]){
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
        int [] arr = {2, 4, 3, 5, 1};

        int ans = mergeSort(arr, 0, arr.length - 1);

        System.out.println("Number of reverse pairs: " + ans);
    }
}
