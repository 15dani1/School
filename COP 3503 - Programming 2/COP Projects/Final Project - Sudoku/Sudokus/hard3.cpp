
#include "Sudoku.h"

int Sudoku::hardSudoku3(){

const int rows = 15;
const int columns = 15;

cout << "          Hard Puzzle 3            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuHard3 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", " ", "1", " ", "|", "9", " ", " ", "|", " ", "4", " ", "|"},
            {" ", "2", "|", "2", " ", " ", "|", "8", " ", " ", "|", "1", "7", " ", "|"},
            {" ", "3", "|", " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", "3", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", " ", " ", "3", "|", " ", "5", " ", "|", " ", " ", "7", "|"},
            {" ", "5", "|", "1", " ", "5", "|", " ", " ", " ", "|", "4", " ", "6", "|"},
            {" ", "6", "|", "7", " ", " ", "|", " ", "2", " ", "|", "9", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "3", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "|"},
            {" ", "8", "|", " ", "6", "1", "|", " ", " ", "9", "|", " ", " ", "5", "|"},
            {" ", "9", "|", " ", "4", " ", "|", " ", " ", "1", "|", " ", "9", " ", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuHard3Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "6", "1", "8", "|", "9", "3", "7", "|", "5", "4", "2", "|"},
            {" ", "2", "|", "2", "3", "4", "|", "8", "6", "5", "|", "1", "7", "9", "|"},
            {" ", "3", "|", "9", "5", "7", "|", "2", "1", "4", "|", "8", "6", "3", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "4", "9", "3", "|", "1", "5", "6", "|", "2", "8", "7", "|"},
            {" ", "5", "|", "1", "2", "5", "|", "7", "9", "8", "|", "4", "3", "6", "|"},
            {" ", "6", "|", "7", "8", "6", "|", "4", "2", "3", "|", "9", "5", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "3", "7", "9", "|", "5", "8", "2", "|", "6", "1", "4", "|"},
            {" ", "8", "|", "8", "6", "1", "|", "3", "4", "9", "|", "7", "2", "5", "|"},
            {" ", "9", "|", "5", "4", "2", "|", "6", "7", "1", "|", "3", "9", "8", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuHard3[i][j] != " "){
        sudokuHard3[i][j] = sudokuHard3[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuHard3[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuHard3 != sudokuHard3Sol){
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

    checker.push_back("A2"); checker.push_back("A5"); checker.push_back("A6"); checker.push_back("A7"); checker.push_back("B1"); checker.push_back("B8"); checker.push_back("B9"); checker.push_back("C4"); checker.push_back("C5"); checker.push_back("C8"); checker.push_back("D1"); checker.push_back("D2"); checker.push_back("E4"); checker.push_back("E6"); checker.push_back("F8"); checker.push_back("F9"); checker.push_back("G2"); checker.push_back("G5"); checker.push_back("G6"); checker.push_back("H1"); checker.push_back("H2"); checker.push_back("H9"); checker.push_back("I3"); checker.push_back("I4"); checker.push_back("I5"); checker.push_back("I8");

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


sudokuHard3[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuHard3[i][j] << " ";
      if(sudokuHard3[i][j] == sudokuHard3Sol[i][j]){

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
  sudoku.hardSudoku3();
}
