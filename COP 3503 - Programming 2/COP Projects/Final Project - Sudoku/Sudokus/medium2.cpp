
#include "Sudoku.h"

int Sudoku::medSudoku2(){

const int rows = 15;
const int columns = 15;

cout << "          Medium Puzzle 2            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuMed2 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", " ", "8", " ", "|", "1", " ", " ", "|", "5", " ", "7", "|"},
            {" ", "2", "|", " ", " ", " ", "|", " ", "4", "7", "|", " ", "9", "3", "|"},
            {" ", "3", "|", "3", " ", " ", "|", " ", "8", " ", "|", " ", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", " ", "6", " ", "|", "2", " ", "3", "|", " ", " ", " ", "|"},
            {" ", "5", "|", "8", " ", " ", "|", " ", " ", " ", "|", " ", " ", "6", "|"},
            {" ", "6", "|", " ", " ", " ", "|", "4", " ", "8", "|", " ", "7", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", " ", "3", "8", "|", " ", "5", " ", "|", " ", " ", "4", "|"},
            {" ", "8", "|", "4", "5", " ", "|", "8", "7", " ", "|", " ", " ", " ", "|"},
            {" ", "9", "|", "9", " ", "6", "|", " ", " ", "4", "|", " ", "8", " ", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuMed2Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "6", "8", "9", "|", "1", "3", "2", "|", "5", "4", "7", "|"},
            {" ", "2", "|", "5", "2", "1", "|", "6", "4", "7", "|", "8", "9", "3", "|"},
            {" ", "3", "|", "3", "7", "4", "|", "5", "8", "9", "|", "1", "6", "2", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "1", "6", "7", "|", "2", "9", "3", "|", "4", "5", "8", "|"},
            {" ", "5", "|", "8", "4", "3", "|", "7", "1", "5", "|", "9", "2", "6", "|"},
            {" ", "6", "|", "2", "9", "5", "|", "4", "6", "8", "|", "3", "7", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "7", "3", "8", "|", "9", "5", "6", "|", "2", "1", "4", "|"},
            {" ", "8", "|", "4", "5", "2", "|", "8", "7", "1", "|", "6", "3", "9", "|"},
            {" ", "9", "|", "9", "1", "6", "|", "3", "2", "4", "|", "7", "8", "5", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuMed2[i][j] != " "){
        sudokuMed2[i][j] = sudokuMed2[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuMed2[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuMed2 != sudokuMed2Sol){
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

    checker.push_back("A3"); checker.push_back("A5"); checker.push_back("A8"); checker.push_back("A9"); checker.push_back("B1"); checker.push_back("B4"); checker.push_back("B7"); checker.push_back("B8"); checker.push_back("C7"); checker.push_back("C9"); checker.push_back("D1");
    checker.push_back("D4"); checker.push_back("D6"); checker.push_back("D8"); checker.push_back("E2"); checker.push_back("E3"); checker.push_back("E7"); checker.push_back("E8"); checker.push_back("F2"); checker.push_back("F4"); checker.push_back("F6"); checker.push_back("F9");
    checker.push_back("G1"); checker.push_back("G3"); checker.push_back("H2"); checker.push_back("H3"); checker.push_back("H6"); checker.push_back("H9"); checker.push_back("I1"); checker.push_back("I2"); checker.push_back("I5"); checker.push_back("I7");

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


sudokuMed2[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuMed2[i][j] << " ";
      if(sudokuMed2[i][j] == sudokuMed2Sol[i][j]){

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
  sudoku.medSudoku2();
}
