//Rahul Dani - Project 2
import java.util.*;
public class CharSorter {

    public static void main(String[] args) { //Main method

        System.out.println("Welcome to Character Sorter Program");
        System.out.println("Please input a string to be sorted");

        Scanner scr = new Scanner(System.in);
        String userStringInput = scr.nextLine(); //This is the String the User Inputs

        int x=0;
        while(true) { //Runs the block till program is exited.
            x++;

            userMenu(userStringInput);

        }
    }

    public static void userMenu(String userStringInput){ //Menu for user to choose from.

        System.out.println("");
        System.out.println("Please select the option you would like to see");
        System.out.println("");
        System.out.println("1. Display character frequencies alphabetically");
        System.out.println("2. Display sorted frequencies");
        System.out.println("3. Show types of character frequencies");
        System.out.println("4. Exit");
        programMenu(userStringInput);

    }

    public static void alphabeticalSort(String userStringInput) { //Sorts the characters alphabetically

        char[] alphabetSort = userStringInput.toCharArray();
        int lengthArray = userStringInput.length();

        for (int i = 0; i < lengthArray - 1; i++) {

            for (int j = i + 1; j < lengthArray; j++) {

                if ((int) alphabetSort[j] < (int) alphabetSort[i]) { //Sorts the characters based on ASCII values.

                    char mySort = alphabetSort[i];
                    alphabetSort[i] = alphabetSort[j];
                    alphabetSort[j] = mySort;
                }
            }
        }

        for (int i = 0; i < lengthArray; i++) {

            int freq = 0;
            for (int j = 0; j < lengthArray; j++){

                if (alphabetSort[i] == alphabetSort[j]){

                    freq++; //Increments Frequency variable.
                }
            }

            if(i == 0){

                System.out.println(alphabetSort[i] + " freq: " + freq); //Displays sort and frequency.

            }

            else if (i != 0) {

                if (!(alphabetSort[i] == alphabetSort[i - 1])) {

                    System.out.println(alphabetSort[i] + " freq: " + freq); //Displays sort and frequency.
                }
            }
        }

        System.out.println("");
    }

    public static void frequencySort(String userStringInput){ //Sorts based on frequency of characters.

        char[] alphabetSort = userStringInput.toCharArray();
        int lengthArray = userStringInput.length();
        int[][] freqChar = new int[2][lengthArray]; //Using a 2D array for this method.
        System.out.println("The sorted by frequency characters are: ");
        System.out.println("");

        for (int i = 0; i < lengthArray - 1; i++) {

            for (int j = i + 1; j < lengthArray; j++) {

                if ((int) alphabetSort[j] < (int) alphabetSort[i]) {

                    char mySort = alphabetSort[i];
                    alphabetSort[i] = alphabetSort[j];      //Similar to the alphabet sorting algorithm.
                    alphabetSort[j] = mySort;
                }
            }
        }

        for (int i = 0; i < lengthArray; i++) {

            int freq = 0;
            for (int j = 0; j < lengthArray; j++){

                if (alphabetSort[i] == alphabetSort[j]){ //Accounts for duplicate characters.

                    freq++;
                }
            }

            if(i == 0){

                freqChar[0][i] = (int)alphabetSort[i];
                freqChar[1][i] = freq;
            }

            else if (i != 0) {

                if (!(alphabetSort[i] == alphabetSort[i - 1])) {

                    freqChar[0][i] = (int)alphabetSort[i]; //An example of casting array value to int.
                    freqChar[1][i] = freq;
                }
            }
        }

        for (int i = 0; i < lengthArray - 1; i++) {

            for (int j = i + 1; j < lengthArray; j++) {

                if (freqChar[1][j] > freqChar[1][i]) {

                    int temp = freqChar[1][i];
                    int tempTwo = freqChar[0][i];
                    freqChar[0][i] = freqChar[0][j];
                    freqChar[1][i] = freqChar[1][j];
                    freqChar[1][j] = temp;
                    freqChar[0][j] = tempTwo; //Sorts frequency.
                }
            }
        }

        for (int i = 0; i < lengthArray - 1; i++) {

            for (int j = i + 1; j < lengthArray; j++) {

                if (freqChar[0][j] < freqChar[0][i] && freqChar[1][j] == freqChar[1][i]) {

                    int temp = freqChar[1][i];
                    int tempTwo = freqChar[0][i];
                    freqChar[0][i] = freqChar[0][j];
                    freqChar[1][i] = freqChar[1][j];
                    freqChar[1][j] = temp;
                    freqChar[0][j] = tempTwo; //Sorts characters based on frequency.
                }
            }
        }

        for (int i=0; i<lengthArray; i++){

            if (freqChar[0][i] != 0) {
                char x = (char) freqChar[0][i];
                System.out.println(x + " freq: " + freqChar[1][i]); //Prints the frequency sorter.
            }
        }

        System.out.println("");
    }

    public static void charTypes(String userStringInput){ //Shows how many of each type of character there is.
                                                            //ASCII characters are used to show the type.
        char[] alphabetSort = userStringInput.toCharArray();
        int lengthArray = userStringInput.length();
        int text = 0;
        int numerical =0;
        int whiteSpace =0;
        int symbol = 0;
        for (int i=0; i<lengthArray; i++) {

            if ((65 <= (int) alphabetSort[i] && (int) alphabetSort[i] <= 90) || (97 <= (int) alphabetSort[i] && (int) alphabetSort[i] <= 122)) {

                text++;

            } else if ((48 <= (int) alphabetSort[i] && (int) alphabetSort[i] <= 57)) {

                numerical++;

            } else if ((int) alphabetSort[i] == 32) {

                whiteSpace++;

            } else {

                symbol++;
            }
        }

        System.out.println("Textual Character count: " + text); //Shows text characters.
        System.out.println("Numerical Character count: " + numerical); //Shows numbers.
        System.out.println("WhiteSpace Character count: " + whiteSpace); //Shows space.
        System.out.println("Symbol Character count: " + symbol); //Shows symbols.
        System.out.println("");
    }

    public static int programMenu(String userStringInput) { //This method checks for correct input of the Menu.

            Scanner scr = new Scanner(System.in);
            int numberInput = 0;

            try {
                numberInput = scr.nextInt();
            } catch (InputMismatchException e) { //Makes sure that only integers are inputted.
                scr.nextLine();
                System.out.println("Error, bad input, please enter a number 1-4");
                userMenu(userStringInput);
            }

            if (numberInput <= 0 || numberInput > 4) { //Makes sure that the inputs inputted are in the range.

                System.out.println("Error, bad input, please enter a number 1-4");
                userMenu(userStringInput);
            }

            MenuCase(numberInput, userStringInput);
            return numberInput;
    }

    public static void MenuCase(int numberInput, String userStringInput) { //Switch case method for the number inputted by the user.

        switch (numberInput) {

            case 1:
                alphabeticalSort(userStringInput); //Goes to alphabetSort method.
                break;

            case 2:
                frequencySort(userStringInput);    //Goes to frequencySort method.
                break;

            case 3:
                charTypes(userStringInput);     //Goes to charTypes method.
                break;

            case 4:                         //Case to exit the program.
                System.out.println("");
                System.out.println("Character Sorter Exited Successfully");
                System.exit(1);
                break;
        }
    }
}
