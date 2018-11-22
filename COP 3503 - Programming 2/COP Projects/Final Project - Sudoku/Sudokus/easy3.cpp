#include "Sudoku.h"

int Sudoku::easySudoku3(){

const int rows = 15;
const int columns = 15;

cout << "          Easy Puzzle 3            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuEasy3 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", " ", "9", "7", "|", "5", " ", "1", "|", "8", " ", " ", "|"},
            {" ", "2", "|", "8", " ", " ", "|", " ", "2", " ", "|", " ", " ", " ", "|"},
            {" ", "3", "|", "1", "2", " ", "|", "4", " ", "3", "|", " ", "9", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "7", "5", " ", "|", " ", " ", " ", "|", " ", "2", " ", "|"},
            {" ", "5", "|", " ", " ", "4", "|", "2", " ", "9", "|", "3", " ", " ", "|"},
            {" ", "6", "|", " ", "8", " ", "|", " ", " ", " ", "|", " ", "1", "9", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", " ", "4", " ", "|", "7", " ", "6", "|", " ", "8", "5", "|"},
            {" ", "8", "|", " ", " ", " ", "|", " ", "5", " ", "|", " ", " ", "1", "|"},
            {" ", "9", "|", " ", " ", "8", "|", "1", " ", "4", "|", "2", "6", " ", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuEasy3Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "4", "9", "7", "|", "5", "6", "1", "|", "8", "3", "2", "|"},
            {" ", "2", "|", "8", "3", "5", "|", "9", "2", "7", "|", "1", "4", "6", "|"},
            {" ", "3", "|", "1", "2", "6", "|", "4", "8", "3", "|", "5", "9", "7", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "7", "5", "9", "|", "3", "1", "8", "|", "6", "2", "4", "|"},
            {" ", "5", "|", "6", "1", "4", "|", "2", "7", "9", "|", "3", "5", "8", "|"},
            {" ", "6", "|", "3", "8", "2", "|", "6", "4", "5", "|", "7", "1", "9", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "2", "4", "1", "|", "7", "3", "6", "|", "9", "8", "5", "|"},
            {" ", "8", "|", "9", "6", "3", "|", "8", "5", "2", "|", "4", "7", "1", "|"},
            {" ", "9", "|", "5", "7", "8", "|", "1", "9", "4", "|", "2", "6", "3", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuEasy3[i][j] != " "){
        sudokuEasy3[i][j] = sudokuEasy3[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuEasy3[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuEasy3 != sudokuEasy3Sol){
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

checker.push_back("A2"); checker.push_back("A3"); checker.push_back("A4"); checker.push_back("B1");
checker.push_back("B3"); checker.push_back("B4"); checker.push_back("B6"); checker.push_back("B7");
checker.push_back("C1"); checker.push_back("C5"); checker.push_back("C9"); checker.push_back("D1");
checker.push_back("D3"); checker.push_back("D5"); checker.push_back("D7"); checker.push_back("D9");
checker.push_back("E2"); checker.push_back("E8"); checker.push_back("F1"); checker.push_back("F3");
checker.push_back("F5"); checker.push_back("F7"); checker.push_back("F9"); checker.push_back("G1");
checker.push_back("G5"); checker.push_back("G9"); checker.push_back("H3"); checker.push_back("H4");
checker.push_back("H6"); checker.push_back("H7"); checker.push_back("H9"); checker.push_back("I6");
checker.push_back("I7"); checker.push_back("I8");

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


sudokuEasy3[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuEasy3[i][j] << " ";
      if(sudokuEasy3[i][j] == sudokuEasy3Sol[i][j]){

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
  sudoku.easySudoku3();
}
