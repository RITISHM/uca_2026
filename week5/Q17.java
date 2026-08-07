package week5;
import java.util.*;

public class Q17 {
  public static void main(String[] args) {
    Scanner sc = new Scanner (System.in);
    System.out.print("how many clinics are there: ");
    int totalClinics = sc.nextInt();

    System.out.print("how many villages are there: ");
    int totalVillages = sc.nextInt();
    int[] population = new int [totalVillages];
    PriorityQueue <int[]> nextVillage = new PriorityQueue<>((a, b) -> Double.compare((double) b[0] / b[1], (double) a[0] / a[1]));

    for(int village = 0; village < totalVillages; village++){
      System.out.print("Enter the population of village " + village + " : ");
      population[village] = sc.nextInt();
      int [] clinicPerVillage = {population[village], 1};
      nextVillage.add(clinicPerVillage);
      totalClinics--;
    }


    System.out.println(totalClinics);
    while(totalClinics--  > 0){
      int [] village = nextVillage.poll();
      village[1]++;
      System.out.println(Arrays.toString(village));
      nextVillage.add(village);
      
    }

    int[] maxLoadedVillage = nextVillage.poll();
    float populationPerVillage = maxLoadedVillage[0]/ (float)maxLoadedVillage[1];
    System.out.printf("%.2f", populationPerVillage);

  }
}
