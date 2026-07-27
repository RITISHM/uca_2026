public class NumberSmallerThanSelf {

    static void mergeSort(int[][] arr, int low, int high, int[] ans) {
        if (low >= high) return;

        int mid = (high - low) / 2 + low;

        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid + 1, high, ans);

        int lp = low, rp = mid + 1;

        while (lp <= mid && rp <= high) {
            if (arr[lp][0] > arr[rp][0]) {
                rp++;
            } else {
                ans[arr[lp][1]] += (rp - (mid + 1));
                lp++;
            }
        }
        
        while (lp <= mid) {
            ans[arr[lp][1]] += (rp - (mid + 1));
            lp++;
        }
        
        merge(arr, low, mid, high);
    }

    static void merge(int[][] arr, int low, int mid, int high) {
        int lp = low;
        int rp = mid + 1;
        int[][] sortedArray = new int[high - low + 1][2];
        int sp = 0;

        while (lp <= mid && rp <= high) {
            if (arr[lp][0] > arr[rp][0]) {
                sortedArray[sp++] = arr[rp++];
            } else {
                sortedArray[sp++] = arr[lp++];
            }
        }

        while (lp <= mid) {
            sortedArray[sp++] = arr[lp++];
        }

        while (rp <= high) {
            sortedArray[sp++] = arr[rp++];
        }

        sp = 0;
        while (low <= high) {
            arr[low++] = sortedArray[sp++];
        }
    }

    public static void main(String[] args) {
        int[] originalArr = {5, 5, 2, 6, 1};
        int n = originalArr.length;
        
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = originalArr[i];
            arr[i][1] = i;
        }
        
        int[] ans = new int[n];
        
        mergeSort(arr, 0, n - 1, ans);
        
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}