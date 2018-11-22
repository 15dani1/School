
#include "Sudoku.h"

int Sudoku::easySudoku1(){

const int rows = 15;
const int columns = 15;

cout << "          Easy Puzzle 1            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuEasy1 [rows][columns] =
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
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
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
/*
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
*/
for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuEasy1[i][j] != " "){
        sudokuEasy1[i][j] = sudokuEasy1[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuEasy1[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuEasy1 != sudokuEasy1Sol){
cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
char letterValue;
int numberValue;
cin >> letterValue >> numberValue;
/*
char alphabet [9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
int numbers [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

for(int i = 0; i < 9; i++){

    if(letterValue == alphabet[i]){
        break;
    }

    else{
      cout << "Invalid arg" << endl;
    }

}

for (int i =0; i < 9; i++){

    if(numberValue != numbers[i]){
      cout << "Invalid num" << endl;
      break;
    }

}

*/
string position = letterValue + to_string(numberValue);
//cout << position;

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

vector<string> checker;

checker.push_back("A1"); checker.push_back("A5"); checker.push_back("B1"); checker.push_back("B2");
checker.push_back("B4"); checker.push_back("B6"); checker.push_back("B8"); checker.push_back("C2");
checker.push_back("C3"); checker.push_back("C4"); checker.push_back("C6"); checker.push_back("C7");
checker.push_back("D1"); checker.push_back("D2"); checker.push_back("D8"); checker.push_back("E3");
checker.push_back("E4"); checker.push_back("E6"); checker.push_back("E7"); checker.push_back("F2");
checker.push_back("F8"); checker.push_back("F9"); checker.push_back("G3"); checker.push_back("G4");
checker.push_back("G6"); checker.push_back("G7"); checker.push_back("G8"); checker.push_back("H2");
checker.push_back("H4"); checker.push_back("H6"); checker.push_back("H8"); checker.push_back("H9");
checker.push_back("I5"); checker.push_back("I9");

for (unsigned int i = 0; i < checker.size(); i++){
        if (position == checker[i]){
          cout << "Error, unable to fill this spot." << endl;
          break;
        }

        else{

        }
}

cout << "";
cout << "Please Enter the Sudoku number in the desired position: ";
string sudokuValue;
cin >> sudokuValue;

cout << "" << endl;


sudokuEasy1[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuEasy1[i][j] << " ";
      if(sudokuEasy1[i][j] == sudokuEasy1Sol[i][j]){

      }

      else {
        a = false;
      }
    }
    cout << endl;
    }

    if(a){

      cout << "Congratulations, you have completed this Easy Sudoku Puzzle!" << endl;
      return 0;
    }

    else {}

    }
}



int main(){

  Sudoku sudoku;
  sudoku.easySudoku1();
}
