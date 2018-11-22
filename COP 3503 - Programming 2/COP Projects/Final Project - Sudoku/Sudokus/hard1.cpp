
#include "Sudoku.h"

int Sudoku::hardSudoku1(){

const int rows = 15;
const int columns = 15;

cout << "          Hard Puzzle 1            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuHard1 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "3", " ", " ", "|", " ", "1", "7", "|", " ", "5", " ", "|"},
            {" ", "2", "|", " ", " ", "1", "|", " ", " ", " ", "|", "8", " ", "4", "|"},
            {" ", "3", "|", " ", " ", " ", "|", "5", "6", " ", "|", " ", " ", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "9", " ", "2", "|", " ", " ", " ", "|", " ", " ", " ", "|"},
            {" ", "5", "|", " ", " ", " ", "|", "6", " ", "3", "|", " ", " ", " ", "|"},
            {" ", "6", "|", " ", " ", " ", "|", " ", " ", " ", "|", "1", " ", "2", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "1", " ", " ", "|", " ", "8", "2", "|", " ", " ", " ", "|"},
            {" ", "8", "|", "7", " ", "8", "|", " ", " ", " ", "|", "2", " ", " ", "|"},
            {" ", "9", "|", " ", "5", " ", "|", "7", "4", " ", "|", " ", " ", "6", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuHard1Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "3", "2", "4", "|", "8", "1", "7", "|", "6", "5", "9", "|"},
            {" ", "2", "|", "5", "6", "1", "|", "2", "3", "9", "|", "8", "7", "4", "|"},
            {" ", "3", "|", "8", "7", "9", "|", "5", "6", "4", "|", "3", "2", "1", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "9", "3", "2", "|", "1", "7", "8", "|", "4", "6", "5", "|"},
            {" ", "5", "|", "4", "1", "5", "|", "6", "2", "3", "|", "7", "9", "8", "|"},
            {" ", "6", "|", "6", "8", "7", "|", "4", "9", "5", "|", "1", "3", "2", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "1", "9", "6", "|", "3", "8", "2", "|", "5", "4", "7", "|"},
            {" ", "8", "|", "7", "4", "8", "|", "9", "5", "6", "|", "2", "1", "3", "|"},
            {" ", "9", "|", "2", "5", "3", "|", "7", "4", "1", "|", "9", "8", "6", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuHard1[i][j] != " "){
        sudokuHard1[i][j] = sudokuHard1[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuHard1[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuHard1 != sudokuHard1Sol){
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

    checker.push_back("A1"); checker.push_back("A4"); checker.push_back("A7"); checker.push_back("A8"); checker.push_back("B9"); checker.push_back("C2"); checker.push_back("C4"); checker.push_back("C8"); checker.push_back("D3"); checker.push_back("D5"); checker.push_back("D9");
    checker.push_back("E1"); checker.push_back("E3"); checker.push_back("E7"); checker.push_back("E9"); checker.push_back("F1");  checker.push_back("F5"); checker.push_back("F7"); checker.push_back("G2"); checker.push_back("G6"); checker.push_back("G8"); checker.push_back("H1");
    checker.push_back("I2"); checker.push_back("I3"); checker.push_back("I6"); checker.push_back("I9");

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

sudokuHard1[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuHard1[i][j] << " ";
      if(sudokuHard1[i][j] == sudokuHard1Sol[i][j]){

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
  sudoku.hardSudoku1();
}
