//Rahul Dani - Lab 6
public class Main {

    public static void main(String[] args) {

        int[][] fillRightArray = new int[5][8];
        fillRight(fillRightArray, 2);
        printArray(fillRightArray);
        System.out.println();

        int[][] fillDownArray = new int[5][8];
        fillDown(fillDownArray, -2);
        printArray(fillDownArray);
        System.out.println();

        System.out.println(getRowSum(fillRightArray, 0));
        System.out.println(getColSum(fillDownArray, 0));

    }

    public static void printArray (int array[][]){

        for(int row=0; row<array.length; row++) {
            for (int column = 0; column < array[0].length; column++) {

                System.out.format("%-10d", array[row][column]);
            }
            System.out.println();
        }
    }

    public static int getColSum (int newArry[][], int colIndex){

        int sum = 0;

        for (int i=0; i<newArry.length; i++){

                sum += newArry[i][colIndex];
            }
        return sum;
    }

    public static int getRowSum(int newArry[][], int rowIndex){

        int sum = 0;

        for (int i=0; i<newArry[rowIndex].length; i++){

            sum += newArry[rowIndex][i];
        }
        return sum;
    }

    public static void fillRight(int fillArr[][], int stepRight){

        int z = 0;
        for (int i=0; i<fillArr.length; i++){
            for (int j=0; j<fillArr[i].length; j++){

                z++;
                fillArr[i][j] = z*stepRight;
            }
        }
    }

    public static void fillDown(int fillArr[][], int stepDown){

        int z = 0;
        for (int i=0; i<fillArr[0].length; i++){
            for (int j=0; j<fillArr.length; j++){

                z++;
                fillArr[j][i] = z*stepDown;
            }
        }
    }
}
