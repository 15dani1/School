#include "Sudoku.h"

int Sudoku::easySudoku2(){

const int rows = 15;
const int columns = 15;

cout << "          Easy Puzzle 2            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuEasy2 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "6", " ", " ", "|", "7", " ", "5", "|", "4", " ", "3", "|"},
            {" ", "2", "|", " ", " ", "3", "|", " ", "2", " ", "|", "7", " ", " ", "|"},
            {" ", "3", "|", " ", " ", " ", "|", " ", " ", "6", "|", " ", "5", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "2", " ", "5", "|", " ", "6", " ", "|", "9", " ", "4", "|"},
            {" ", "5", "|", " ", "7", " ", "|", " ", " ", " ", "|", " ", "1", " ", "|"},
            {" ", "6", "|", "9", " ", "1", "|", " ", "7", " ", "|", "5", " ", "8", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "5", "3", " ", "|", "8", " ", " ", "|", " ", " ", " ", "|"},
            {" ", "8", "|", " ", " ", "8", "|", " ", "9", " ", "|", "3", " ", " ", "|"},
            {" ", "9", "|", "7", " ", "6", "|", "1", " ", "3", "|", " ", " ", "9", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuEasy2Sol [rows][columns] =
    {

            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "6", "9", "2", "|", "7", "1", "5", "|", "4", "8", "3", "|"},
            {" ", "2", "|", "1", "5", "3", "|", "4", "2", "8", "|", "7", "9", "6", "|"},
            {" ", "3", "|", "8", "4", "7", "|", "9", "3", "6", "|", "2", "5", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "2", "8", "5", "|", "3", "6", "1", "|", "9", "7", "4", "|"},
            {" ", "5", "|", "3", "7", "4", "|", "5", "8", "9", "|", "6", "1", "2", "|"},
            {" ", "6", "|", "9", "6", "1", "|", "2", "7", "4", "|", "5", "3", "8", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "5", "3", "9", "|", "8", "4", "2", "|", "1", "6", "7", "|"},
            {" ", "8", "|", "4", "1", "8", "|", "6", "9", "7", "|", "3", "2", "5", "|"},
            {" ", "9", "|", "7", "2", "6", "|", "1", "5", "3", "|", "8", "4", "9", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},

  };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuEasy2[i][j] != " "){
        sudokuEasy2[i][j] = sudokuEasy2[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuEasy2[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuEasy2 != sudokuEasy2Sol){
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

checker.push_back("A1"); checker.push_back("A4"); checker.push_back("A6"); checker.push_back("A7");
checker.push_back("A9"); checker.push_back("B5"); checker.push_back("B7"); checker.push_back("C2");
checker.push_back("C4"); checker.push_back("C6"); checker.push_back("C8"); checker.push_back("C9");
checker.push_back("D1"); checker.push_back("D7"); checker.push_back("D9"); checker.push_back("E2");
checker.push_back("E4"); checker.push_back("E6"); checker.push_back("E8"); checker.push_back("F1");
checker.push_back("F3"); checker.push_back("F9"); checker.push_back("G1"); checker.push_back("G2");
checker.push_back("G4"); checker.push_back("G6"); checker.push_back("G8"); checker.push_back("H3");
checker.push_back("H5"); checker.push_back("I1"); checker.push_back("I3"); checker.push_back("I4");
checker.push_back("I6"); checker.push_back("I9");

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


sudokuEasy2[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuEasy2[i][j] << " ";
      if(sudokuEasy2[i][j] == sudokuEasy2Sol[i][j]){

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
  sudoku.easySudoku2();
}
