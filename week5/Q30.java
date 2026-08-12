import java.util.PriorityQueue;
import java.util.Collections;

class MedianFinder {
    
    private PriorityQueue<Integer> lowerHalf; 
    private PriorityQueue<Integer> upperHalf; 

    public MedianFinder() {
        lowerHalf = new PriorityQueue<>(Collections.reverseOrder());
        upperHalf = new PriorityQueue<>();
    }

    public void insert(int num) {
        lowerHalf.offer(num);
        upperHalf.offer(lowerHalf.poll());
        
        if (lowerHalf.size() < upperHalf.size()) {
            lowerHalf.offer(upperHalf.poll());
        }
    }
    
    public float getMedian() {
        if (lowerHalf.size() > upperHalf.size()) {
            return (float) lowerHalf.peek();
        }
        
        return (float) (lowerHalf.peek() + upperHalf.peek()) / 2.0f;
    }

    public void addNum(int num) {
        insert(num);
    }

    public double findMedian() {
        return (double) getMedian();
    }
}


class Q30 {
    public static void main(String[] args) {
        MedianFinder medianFinder = new MedianFinder();
        int[] numbers = {5, 15, 1, 3};
        
        for (int num : numbers) {
            medianFinder.addNum(num);
            System.out.println("Inserted: " + num + ", Current Median: " + medianFinder.findMedian());
        }
    }
}



/*
Approch:

- I have used two heaps to maintain the lower half and upper half of the numbers.
- The lower half is a max-heap (to get the maximum of the lowerhalf)
- The upper half is a min-heap (to get the minimum of the upperhalf)
- when a new number is added, it is first adde to the lower half, then the maximum of the lower half is moved to the upper half.
- If the size of the lower half is less than the upper half, then the minimum of the upper half is moved to the lower half.
- The median is calculated based on the sizes of the two heaps. If the lower half has more elements, the median is the maximum of the lower half. 
  If both halves have the same size, the median is the average of the maximum of the lower half and the minimum of the upper half.  

*/