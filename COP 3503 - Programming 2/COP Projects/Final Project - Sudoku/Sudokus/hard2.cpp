
#include "Sudoku.h"

int Sudoku::hardSudoku2(){

const int rows = 15;
const int columns = 15;

cout << "          Hard Puzzle 2            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuHard2 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", " ", "8", "9", "|", " ", " ", " ", "|", "6", " ", " ", "|"},
            {" ", "2", "|", " ", "5", " ", "|", " ", "9", "6", "|", " ", " ", " ", "|"},
            {" ", "3", "|", "2", " ", " ", "|", "8", "4", " ", "|", " ", "1", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", " ", " ", " ", "|", " ", " ", " ", "|", "5", "6", " ", "|"},
            {" ", "5", "|", " ", " ", " ", "|", "1", " ", "7", "|", " ", " ", " ", "|"},
            {" ", "6", "|", " ", "3", "6", "|", " ", " ", " ", "|", " ", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", " ", "7", " ", "|", " ", "5", "8", "|", " ", " ", "2", "|"},
            {" ", "8", "|", " ", " ", " ", "|", "2", "1", " ", "|", " ", "5", " ", "|"},
            {" ", "9", "|", " ", " ", "5", "|", " ", " ", " ", "|", "9", "4", " ", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuHard2Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "4", "8", "9", "|", "3", "2", "1", "|", "6", "7", "5", "|"},
            {" ", "2", "|", "3", "5", "1", "|", "7", "9", "6", "|", "2", "8", "4", "|"},
            {" ", "3", "|", "2", "6", "7", "|", "8", "4", "5", "|", "3", "1", "9", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "9", "1", "8", "|", "4", "3", "2", "|", "5", "6", "7", "|"},
            {" ", "5", "|", "5", "4", "2", "|", "1", "6", "7", "|", "8", "9", "3", "|"},
            {" ", "6", "|", "7", "3", "6", "|", "5", "8", "9", "|", "4", "2", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "6", "7", "4", "|", "9", "5", "8", "|", "1", "3", "2", "|"},
            {" ", "8", "|", "8", "9", "3", "|", "2", "1", "4", "|", "7", "5", "6", "|"},
            {" ", "9", "|", "1", "2", "5", "|", "6", "7", "3", "|", "9", "4", "8", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuHard2[i][j] != " "){
        sudokuHard2[i][j] = sudokuHard2[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuHard2[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuHard2 != sudokuHard2Sol){
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

    checker.push_back("A3"); checker.push_back("B1"); checker.push_back("B2"); checker.push_back("B6"); checker.push_back("B7"); checker.push_back("C1"); checker.push_back("C6"); checker.push_back("C9"); checker.push_back("D3"); checker.push_back("D5"); checker.push_back("D7"); checker.push_back("E2"); checker.push_back("E3"); checker.push_back("E7"); checker.push_back("E8"); checker.push_back("F2"); checker.push_back("F5"); checker.push_back("F7"); checker.push_back("G1"); checker.push_back("G4"); checker.push_back("G9"); checker.push_back("H3"); checker.push_back("H4"); checker.push_back("H8"); checker.push_back("H9"); checker.push_back("I7");

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


sudokuHard2[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuHard2[i][j] << " ";
      if(sudokuHard2[i][j] == sudokuHard2Sol[i][j]){

      }

      else {
        a = false;
      }
    }
    cout << endl;
    }

    if(a){

      cout << "Congratulations, you have completed this Hard Sudoku Puzzle!" << endl;
      return 0;
    }

    else {}

    }
}



int main(){

  Sudoku sudoku;
  sudoku.hardSudoku2();
}
