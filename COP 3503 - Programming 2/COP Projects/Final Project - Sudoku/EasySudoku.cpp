
#include "Sudoku.h"

int Sudoku::easySudoku1(){

const int rows = 15;
const int columns = 14;

cout << "          Easy Puzzle 1            " << endl;
cout << "" << endl;

  /*  string sudokuEasy1 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "9", "1", " ", "|", "7", " ", " ", "|", " ", " ", " ", "|"},
            {" ", "2", "|", " ", "3", "2", "|", "6", " ", "9", "|", " ", "8", " ", "|"},
            {" ", "3", "|", " ", " ", "7", "|", " ", "8", " ", "|", "9", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", " ", "8", "6", "|", " ", "3", " ", "|", "1", "7", " ", "|"},
            {" ", "5", "|", "3", " ", " ", "|", " ", " ", " ", "|", " ", " ", "6", "|"},
            {" ", "6", "|", " ", "5", "1", "|", " ", "2", " ", "|", "8", "4", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", " ", " ", "9", "|", " ", "5", " ", "|", "3", " ", " ", "|"},
            {" ", "8", "|", " ", "2", " ", "|", "3", " ", "1", "|", "4", "9", " ", "|"},
            {" ", "9", "|", " ", " ", " ", "|", " ", " ", "2", "|", " ", "6", "1", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
*/
    string sudokuEasy1Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "9", "1", "8", "|", "7", "4", "5", "|", "6", "3", "2", "|"},
            {" ", "2", "|", "5", "3", "2", "|", "6", "1", "9", "|", "7", "8", "4", "|"},
            {" ", "3", "|", "6", "4", "7", "|", "2", "8", "3", "|", "9", "1", "5", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "2", "8", "6", "|", "5", "3", "4", "|", "1", "7", "9", "|"},
            {" ", "5", "|", "3", "9", "4", "|", "1", "7", "8", "|", "2", "5", "6", "|"},
            {" ", "6", "|", "7", "5", "1", "|", "9", "2", "6", "|", "8", "4", "3", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "1", "6", "9", "|", "4", "5", "7", "|", "3", "2", "8", "|"},
            {" ", "8", "|", "8", "2", "5", "|", "3", "6", "1", "|", "4", "9", "7", "|"},
            {" ", "9", "|", "4", "7", "3", "|", "8", "9", "2", "|", "5", "6", "1", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

    string sudokuEasy1 [rows][columns] =

    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "9", "1", "8", "|", "7", "4", "5", "|", "6", "3", "2", "|"},
            {" ", "2", "|", "5", "3", "2", "|", "6", "1", "9", "|", "7", "8", "4", "|"},
            {" ", "3", "|", "6", "4", "7", "|", "2", "8", "3", "|", "9", "1", "5", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "2", "8", "6", "|", "5", "3", "4", "|", "1", "7", "9", "|"},
            {" ", "5", "|", "3", "9", "4", "|", "1", "7", "8", "|", "2", "5", "6", "|"},
            {" ", "6", "|", "7", " ", "1", "|", "9", "2", "6", "|", "8", "4", "3", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "1", "6", "9", "|", "4", "5", "7", "|", "3", "2", "8", "|"},
            {" ", "8", "|", "8", "2", "5", "|", "3", "6", "1", "|", "4", "9", "7", "|"},
            {" ", "9", "|", "4", "7", "3", "|", "8", "9", "2", "|", "5", "6", "1", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuEasy1[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuEasy1 != sudokuEasy1Sol){
cout << "Please Enter the Letter Position of the Grid in which you would like to fill a value: ";
char letterValue;
cin >> letterValue;

int myLetterVal = (int)letterValue;

if(myLetterVal == 65){
  myLetterVal = 3;
}
else if(myLetterVal == 66){
  myLetterVal = 4;
}
else if(myLetterVal == 67){
  myLetterVal = 5;
}
else if(myLetterVal == 68){
  myLetterVal = 7;
}
else if(myLetterVal == 69){
  myLetterVal = 8;
}
else if(myLetterVal == 70){
  myLetterVal = 9;
}
else if(myLetterVal == 71){
  myLetterVal = 11;
}
else if(myLetterVal == 72){
  myLetterVal = 12;
}
else if(myLetterVal == 73){
  myLetterVal = 13;
}
else {
  cout << "Error Invalid Letter" << endl;
}

cout << "";
cout << "Please Enter the Number Position of the Grid in which you would like to fill a value: ";
int numberValue;
cin >> numberValue;

if (numberValue >= 1 && numberValue <=3){

    numberValue = numberValue + 1;
}
else if(numberValue > 3 && numberValue <=6){
    numberValue = numberValue + 2;
}

else if(numberValue > 6 && numberValue <= 9){

  numberValue = numberValue + 3;
}

else {
  cout << "Error Invalid Number" << endl;
}

cout << "";
cout << "Please Enter the Sudoku number in the desired position: ";
string sudokuValue;
cin >> sudokuValue;

cout << "" << endl;

sudokuEasy1[numberValue][myLetterVal] = sudokuValue;

for(int i=0; i < 15; i++){

    for(int j=0; j < 14; j++) {

      cout << sudokuEasy1[i][j] << " ";
    }
    cout << endl;
    }
    int counter=0;
for(int K=0; K < 15; K++){

    for(int X=0; X < 15; X++) {
      int t=0;


      if(sudokuEasy1[K][X] == sudokuEasy1Sol[K][X]){
        counter++;
            return 0;
      }
      else{
        cout << "You lose";
        break;
      }
    }
    }
if (counter == 225){
  cout << "Congradulations, you have completed this Easy Sudoku Puzzle!" << endl;
   //cout<<sudokuEasy1[K][X];
   cout<<"\n";
   cout<<"bbbb"<< sudokuEasy1Sol[6][6];
}

/*for(int i=0; i <= 15; i++){
    for(int j=0; j <= 15; j++){

      if(sudokuEasy1[i][j] == sudokuEasy1Sol[i][j]){
          a = false;
          cout << "Congradulations, you have completed this Easy Sudoku Puzzle!" << endl;
      }
      else
        a = true;

    }
    */

}
}



int main(){

  Sudoku sudoku;
  sudoku.easySudoku1();
}
