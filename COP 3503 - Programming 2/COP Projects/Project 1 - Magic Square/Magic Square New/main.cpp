//Rahul Dani - COP 3503 Project 1 - Magic Square.
#include "Magic Square Header.h"

// A function to generate odd sized magic squares

void sumCheck(int **RdSquare, int n){

    cout <<"" <<endl;
    cout << "Checking the sum of every row:      ";

    for (int i=0; i<=n-1; i++){
        int totalRow=0;
        for (int j=0; j<=n-1; j++){

            totalRow = totalRow + RdSquare[i][j];
        }

        cout << totalRow << " ";
    }

    cout << endl;
    cout << "Checking the sum of every column:   ";

    for (int i=0; i<=n-1; i++){
        int totalCol=0;
        for (int j=0; j<=n-1; j++){

            totalCol = totalCol + RdSquare[j][i];
        }

        cout << totalCol << " ";
    }

    cout << endl;
    cout << "Checking the sum of every diagonal: ";

    int totalDiag1 =0;

    for (int i=0; i<=n-1; i++){

        totalDiag1 = totalDiag1 + RdSquare[i][i];
    }

    cout << totalDiag1 << " ";

    int totalDiag2 =0;

    for (int j=0; j<=n-1; j++){

        totalDiag2 = totalDiag2 + RdSquare[j][n-1-j];
    }

    cout << totalDiag2 << endl;

    cout << "";
}

void magicSquares(int **RdSquare, int n) {
    // Print magic square

    cout << "Magic Square #1 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //1st print
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", RdSquare[i][j]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #2 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //2nd print
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", RdSquare[j][i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #3 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //3rd print
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", RdSquare[i][n - 1 - j]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #4 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) //4th print
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", RdSquare[j][n - 1 - i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #5 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", RdSquare[n - 1 - j][i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #6 is:" << endl;
    cout << "" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", RdSquare[n - 1 - i][j]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #7 is:" << endl;
    cout << "" << endl;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--)
            printf("%3d ", RdSquare[i][j]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    cout << "" << endl;
    cout << "Magic Square #8 is:" << endl;
    cout << "" << endl;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--)
            printf("%3d ", RdSquare[j][i]);
        printf("\n");
    }

    sumCheck(RdSquare, n);

    if (n != 3) {
        cout << "" << endl;
        cout << "Magic Square #9 is:" << endl;
        cout << "" << endl;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--)

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

        sumCheck(RdSquare, n);

        cout << "" << endl;
        cout << "Magic Square #10 is:" << endl;
        cout << "" << endl;

        for (int i = 0; i < n; i++) //1st print
        {
            for (int j = 0; j < n; j++)
                printf("%3d ", RdSquare[i][j]);
            printf("\n");
        }

        sumCheck(RdSquare, n);
    }
    delete[] RdSquare;

}

void generateSquare(int n)
{

    int **RdSquare = new int*[n];

    // set all slots as 0
    for (int i =0; i<n; i++){

        RdSquare[i]=new int[n];

        for(int j=0;j<n;j++){

            RdSquare[i][j]=0;
        }
    }

    // Initialize position for 1
    int i = n/2;
    int j = n-1;

    // One by one put all values in magic square
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



// Driver program to test above function

int main()
{
    int x;
    cout << "Enter the size of a magic square: ";
    cin >> x;
    cout << "" <<endl;
    int n =x; // Works only when n is odd
    generateSquare(n);
    return 0;
}
