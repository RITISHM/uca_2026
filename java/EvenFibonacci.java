import java.util.Scanner;
class EvenFibonacci{

    public static int bruteForce(int n){
      
      int sum = 0;
      int i = 0;
      for (int a = 0, b = 2; b < n;){

        if (b % 2 == 0) sum += b;

        int nextTerm = a + b;
        a = b;
        b = nextTerm;
        i++;
      }
      System.out.println("Number of iteration in brute force = " + i);

      return sum;

    }

    public static int optimal(int n){
      
      int sum = 0;
      int i = 0;

      for (int a = 0, b = 2; b < n;){
        sum += b;

        int nextEven = 4 * b + a;

        a = b;
        b = nextEven;

        i++;
      }
      System.out.println("Number of iteration in optimal approch = " + i);

      return sum;

    }

    public static void main (String[] args) {
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter the number = ");
      int n = sc.nextInt();

      int res = bruteForce(n);
      System.out.println("Result of bruete force = " + res);

      res = optimal(n);
      System.out.println("Result of Optimal = " + res);
       
    }


}