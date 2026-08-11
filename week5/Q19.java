package week5;
import java.util.Arrays;

class Q19 {

  public static void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        boolean flag1 = false;
        boolean flag2 = false;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(matrix[row][col] == 0) { 
                    if(row == 0) flag1 = true;
                    if(col == 0) flag2 = true;
                    matrix[row][0] = 0; 
                    matrix[0][col] = 0;
                }
            }
        }

        for(int row = 1; row < rows; row++){
                for(int col = 1; col < cols; col++){
                    if(matrix[row][0] == 0 || matrix[0][col] == 0 )matrix[row][col] = 0;
            }
        }

        
        if(flag1){
            for(int col = 0; col < cols; col++){
                matrix[0][col] = 0;
            }
        }
        if(flag2){
            for(int row = 0; row < rows; row++){
                matrix[row][0] = 0;
            }
        }

    }

    public static void main(String[] args) {
      int [][] matrix = {{1,1,1},{1,0,1},{1,1,1}};
      setZeroes(matrix);
      System.out.println(Arrays.deepToString(matrix));
    }

}
