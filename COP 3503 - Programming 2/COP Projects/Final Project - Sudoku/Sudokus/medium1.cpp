
#include "Sudoku.h"

int Sudoku::medSudoku1(){

const int rows = 15;
const int columns = 15;

cout << "          Med Puzzle 1            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuMed1 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "9", " ", "7", "|", " ", "1", " ", "|", " ", "4", " ", "|"},
            {" ", "2", "|", " ", "8", "2", "|", " ", " ", "4", "|", " ", " ", "7", "|"},
            {" ", "3", "|", "1", "4", " ", "|", "7", "3", " ", "|", " ", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", " ", " ", " ", "|", "4", " ", "7", "|", " ", " ", "3", "|"},
            {" ", "5", "|", " ", "7", " ", "|", " ", " ", " ", "|", " ", "2", " ", "|"},
            {" ", "6", "|", "2", " ", " ", "|", "5", " ", "9", "|", " ", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", " ", " ", " ", "|", " ", "4", "3", "|", " ", "9", "8", "|"},
            {" ", "8", "|", "7", " ", " ", "|", "6", " ", " ", "|", "1", "3", " ", "|"},
            {" ", "9", "|", " ", "9", " ", "|", " ", "7", " ", "|", "6", " ", "2", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuMed1Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "9", "3", "7", "|", "8", "1", "2", "|", "5", "4", "6", "|"},
            {" ", "2", "|", "6", "8", "2", "|", "9", "5", "4", "|", "3", "1", "7", "|"},
            {" ", "3", "|", "1", "4", "5", "|", "7", "3", "6", "|", "2", "8", "9", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "8", "5", "1", "|", "4", "2", "7", "|", "9", "6", "3", "|"},
            {" ", "5", "|", "4", "7", "9", "|", "3", "6", "1", "|", "8", "2", "5", "|"},
            {" ", "6", "|", "2", "6", "3", "|", "5", "8", "9", "|", "4", "7", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "5", "1", "6", "|", "2", "4", "3", "|", "7", "9", "8", "|"},
            {" ", "8", "|", "7", "2", "8", "|", "6", "9", "5", "|", "1", "3", "4", "|"},
            {" ", "9", "|", "3", "9", "4", "|", "1", "7", "8", "|", "6", "5", "2", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuMed1[i][j] != " "){
        sudokuMed1[i][j] = sudokuMed1[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuMed1[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuMed1 != sudokuMed1Sol){
cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
char letterValue;
int numberValue;
cin >> letterValue >> numberValue;

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

    checker.push_back("A1"); checker.push_back("A3"); checker.push_back("A6"); checker.push_back("A8"); checker.push_back("B2"); checker.push_back("B3"); checker.push_back("B5"); checker.push_back("B9"); checker.push_back("C1"); checker.push_back("C2"); checker.push_back("D3");
    checker.push_back("D4"); checker.push_back("D6"); checker.push_back("D8"); checker.push_back("E1"); checker.push_back("E3"); checker.push_back("E7"); checker.push_back("E9"); checker.push_back("F2"); checker.push_back("F4"); checker.push_back("F6"); checker.push_back("F7");
    checker.push_back("G8"); checker.push_back("G9"); checker.push_back("H1"); checker.push_back("H5"); checker.push_back("H7"); checker.push_back("H8"); checker.push_back("I2"); checker.push_back("I4"); checker.push_back("I7"); checker.push_back("I9");

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


sudokuMed1[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuMed1[i][j] << " ";
      if(sudokuMed1[i][j] == sudokuMed1Sol[i][j]){

      }

      else {
        a = false;
      }
    }
    cout << endl;
    }

    if(a){

      cout << "Congratulations, you have completed this Medium Sudoku Puzzle!" << endl;
      return 0;
    }

    else {}

    }
}



int main(){

  Sudoku sudoku;
  sudoku.medSudoku1();
}
