//Rahul Dani - COP 3503 Project 1 - Magic Square.
#include "pa1.h"    //use of header file to incorporate the includes and namespace.

// A program that is used to generate odd sized magic squares.

void sumCheck(int **RdSquare, int n){ //Method for calculating the sum of the rows, columns,
                                      //and diagonals.
    cout <<"" <<endl;
    cout << "Checking the sum of every row:      ";

    for (int i=0; i<=n-1; i++){        //Calculates row sums.
        int totalRow=0;
        for (int j=0; j<=n-1; j++){

            totalRow = totalRow + RdSquare[i][j];
        }

        cout << totalRow << " ";
    }

    cout << endl;
    cout << "Checking the sum of every column:   ";

    for (int i=0; i<=n-1; i++){       //Calculates column sums.
        int totalCol=0;
        for (int j=0; j<=n-1; j++){

            totalCol = totalCol + RdSquare[j][i];
        }

        cout << totalCol << " ";
    }

    cout << endl;
    cout << "Checking the sum of every diagonal: ";
    int totalDiag1 =0;

    for (int i=0; i<=n-1; i++){        //Calculates first diagonal sum.

        totalDiag1 = totalDiag1 + RdSquare[i][i];
    }

    cout << totalDiag1 << " ";
    int totalDiag2 =0;

    for (int j=0; j<=n-1; j++){     //Calculates second diagonal sum.

        totalDiag2 = totalDiag2 + RdSquare[j][n-1-j];
    }

    cout << totalDiag2 << endl;
    cout << "";
}

void magicSquares(int **RdSquare, int n) {  // Method to print magic squares.

    cout << "Magic Square #1 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //1st square print.
    {
        for (int j = 0; j < n; j++)       //Base configuration of the square.
            printf("%3d ", RdSquare[i][j]);
        printf("\n");
    }

    sumCheck(RdSquare, n); //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #2 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //2nd square print.
    {
        for (int j = 0; j < n; j++)    //Diagonal reflection of the base configuration.
            printf("%3d ", RdSquare[j][i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #3 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //3rd square print.
    {
        for (int j = 0; j < n; j++)     //90 degree clockwise rotation of square 2.
            printf("%3d ", RdSquare[i][n - 1 - j]);
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #4 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //4th square print.
    {
        for (int j = 0; j < n; j++)    //90 degree counterclockwise rotation of square 1.
            printf("%3d ", RdSquare[j][n - 1 - i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #5 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //5th square print.
    {
        for (int j = 0; j < n; j++)     //90 degree clockwise rotation of square 1.
            printf("%3d ", RdSquare[n - 1 - j][i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #6 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //6th square print.
    {
        for (int j = 0; j < n; j++)     //90 degree counterclockwise rotation of square 2.
            printf("%3d ", RdSquare[n - 1 - i][j]);
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #7 is:" << endl;
    cout << "" << endl;

    for (int i = n - 1; i >= 0; i--)  //7th square print.
    {
        for (int j = n - 1; j >= 0; j--)    //180 degree counterclockwise
            printf("%3d ", RdSquare[i][j]); //rotation of square 1.
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    cout << "" << endl;
    cout << "Magic Square #8 is:" << endl;
    cout << "" << endl;

    for (int i = n - 1; i >= 0; i--)  //8th square print.
    {
        for (int j = n - 1; j >= 0; j--)    //180 degree counterclockwise
            printf("%3d ", RdSquare[j][i]); //rotation of square 2.
        printf("\n");
    }

    sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

    if (n != 3) {       //Only prints square #9 and #10 if square is greater than 3x3.
        cout << "" << endl;
        cout << "Magic Square #9 is:" << endl;
        cout << "" << endl;

        for (int i = n - 1; i >= 0; i--) //9th square print.
        {
            for (int j = n - 1; j >= 0; j--)    //Flips the first two and last
                                                //two columns of square 7.
                if (j == n - 1 || j == 1) {
                    int temp = 0;
                    temp = RdSquare[i][j - 1];
                    RdSquare[i][j - 1] = RdSquare[i][j];
                    RdSquare[i][j] = temp;
                    printf("%3d ", RdSquare[i][j]);
                } else {

                    printf("%3d ", RdSquare[i][j]);
                }
            printf("\n");

        }

        sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.

        cout << "" << endl;
        cout << "Magic Square #10 is:" << endl;
        cout << "" << endl;

        for (int i = 0; i < n; i++) //10th square print.
        {
            for (int j = 0; j < n; j++)         //Flips the first two and last
                printf("%3d ", RdSquare[i][j]);  //two columns of square 1.
            printf("\n");
        }

        sumCheck(RdSquare, n);  //Calls method for checking row, column, and diagonal sums.
    }
    delete[] RdSquare;  //Deletes the pointer created.

}

void generateSquare(int n) //Algorithm used to generate the magic squares.
{
    int **RdSquare = new int*[n]; //Using pointers instead of user-inputted array size

    // Sets all the slots in the square as 0.
    for (int i =0; i<n; i++)
    {
        RdSquare[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            RdSquare[i][j]=0;
        }
    }
    // Initialize position for 1
    int i = n/2;
    int j = n-1;

    // Puts the values into the square.
    for (int num=1; num <= n*n; )
    {
        if (i==-1 && j==n) //3rd condition
        {
            j = n-2;
            i = 0;
        }
        else
        {
            //1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;
            //1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i=n-1;
        }
        if (RdSquare[i][j]) //2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            RdSquare[i][j] = num++; //set number

        j++; i--; //1st condition
    }
    magicSquares(RdSquare, n);
}

// Main program to test above function
int main()
{
    int n;        //Initialize a variable n
    cout << "Enter the size of a magic square: ";
    cin >> n;        //User inputs size of the square.
    cout << "" <<endl;
    generateSquare(n); //Runs the generateSquare method.
    return 0;
}
