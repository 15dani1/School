
#include "Sudoku.h"

int Sudoku::medSudoku3(){

const int rows = 15;
const int columns = 15;

cout << "          Medium Puzzle 3            " << endl;
cout << "" << endl;
//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

   string sudokuMed3 [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "7", "9", " ", "|", " ", " ", " ", "|", " ", " ", " ", "|"},
            {" ", "2", "|", "8", " ", "1", "|", " ", " ", "9", "|", " ", "7", " ", "|"},
            {" ", "3", "|", " ", "4", "6", "|", " ", "7", " ", "|", " ", " ", "8", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", " ", " ", "7", "|", "6", " ", "3", "|", " ", "5", " ", "|"},
            {" ", "5", "|", "1", " ", "2", "|", " ", " ", " ", "|", "6", " ", "7", "|"},
            {" ", "6", "|", " ", "6", " ", "|", "7", " ", "8", "|", "2", " ", " ", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "6", " ", " ", "|", " ", "9", " ", "|", "8", "2", " ", "|"},
            {" ", "8", "|", " ", "7", " ", "|", "2", " ", " ", "|", "4", " ", "9", "|"},
            {" ", "9", "|", " ", " ", " ", "|", " ", " ", " ", "|", " ", "1", "5", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };
//SetConsoleTextAttribute(h, 0XF | FOREGROUND_INTENSITY );
    string sudokuMed3Sol [rows][columns] =
    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "7", "9", "3", "|", "1", "8", "2", "|", "5", "4", "6", "|"},
            {" ", "2", "|", "8", "5", "1", "|", "4", "6", "9", "|", "3", "7", "2", "|"},
            {" ", "3", "|", "2", "4", "6", "|", "3", "7", "5", "|", "1", "9", "8", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "4", "8", "7", "|", "6", "2", "3", "|", "9", "5", "1", "|"},
            {" ", "5", "|", "1", "3", "2", "|", "9", "5", "4", "|", "6", "8", "7", "|"},
            {" ", "6", "|", "9", "6", "5", "|", "7", "1", "8", "|", "2", "3", "4", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "6", "1", "4", "|", "5", "9", "7", "|", "8", "2", "3", "|"},
            {" ", "8", "|", "5", "7", "8", "|", "2", "3", "1", "|", "4", "6", "9", "|"},
            {" ", "9", "|", "3", "2", "9", "|", "8", "4", "6", "|", "7", "1", "5", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuMed3[i][j] != " "){
        sudokuMed3[i][j] = sudokuMed3[i][j];
      }
  }
}

//SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuMed3[i][j] << " ";
        }
        cout << endl;
    }

while(sudokuMed3 != sudokuMed3Sol){
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

    checker.push_back("A1"); checker.push_back("A2"); checker.push_back("A5"); checker.push_back("A7"); checker.push_back("B1"); checker.push_back("B3"); checker.push_back("B6"); checker.push_back("B8"); checker.push_back("C2"); checker.push_back("C3"); checker.push_back("C4");
    checker.push_back("C5"); checker.push_back("D4"); checker.push_back("D7"); checker.push_back("D8"); checker.push_back("E3"); checker.push_back("E7"); checker.push_back("F2"); checker.push_back("F4"); checker.push_back("F6"); checker.push_back("G5"); checker.push_back("G6");
    checker.push_back("G7"); checker.push_back("G8"); checker.push_back("H2"); checker.push_back("H4"); checker.push_back("H7"); checker.push_back("H9"); checker.push_back("I3"); checker.push_back("I5"); checker.push_back("I8"); checker.push_back("I9");

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


sudokuMed3[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 15; i++){

    for(int j=0; j < 15; j++) {

      cout << sudokuMed3[i][j] << " ";
      if(sudokuMed3[i][j] == sudokuMed3Sol[i][j]){

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
  sudoku.medSudoku3();
}
