//COP 3503 Final Project.

#include "Sudoku.h"


int Sudoku::selDifficulty(){

    cout << "" << endl;
    cout << "Select Difficulty: " << endl;
    cout << "" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "4. Bonus(Hexadoku)" << endl;
    cout << "5. Return to Main Menu" << endl;
    cout << "" << endl;
    cout << "Enter your selection here: ";

    int diffChoice;
    cin >> diffChoice;

    switch(diffChoice){

      case 1:
          cout << "Easy";
          break;

      case 2:
          cout << "Medium";
          break;

      case 3:
          cout << "Hard";
          break;

      case 4:
          cout << "Bonus(Hexadoku)";
          break;

      case 5:
          menu();
          break;

      default:
        cout << "Invalid choice. Please try again." << endl;
    }

    return 0;
}

int Sudoku::highScores(){

  cout << "" << endl;
  cout << "High scores: " << endl;
  cout << "" << endl;
  cout << "Select from the following options:" << endl;
  cout << "" << endl;
  cout << "1. Return to Main Menu" << endl;
  cout << "2. Exit the Puzzle" << endl;
  cout << "" << endl;
  cout << "Enter your selection here: ";

  int highscoreChoice;
  cin >> highscoreChoice;

if(highscoreChoice == 1){
    menu();
    return 0;
}

else if (highscoreChoice == 2){
    exitPuzzle();
    return 0;
}

else {
  cout << "Invalid choice. Please try again." << endl;
  highScores();
}
  return 0;

}

int Sudoku::exitPuzzle(){

    cout << "" << endl;
    cout << "Are you sure you want to exit?" << endl;
    cout << "" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "" << endl;
    cout << "Please enter your choice here (1 or 2): ";
    int exitChoice;
    cin >> exitChoice;
    cout << "" << endl;

    if(exitChoice == 2){
      menu();
      return 0;
    }

    else if (exitChoice == 1){
      return 0;
    }

    else {
      cout << "Invalid choice. Please try again." << endl;
      exitPuzzle();
    }
}

int Sudoku::menuSelection(int userSelect){

switch (userSelect){

  case 1:
    selDifficulty();
    break;

  case 2:
    highScores();
    break;

  case 3:
    exitPuzzle();
    break;

  default:
    cout << "Invalid choice. Please try again." << endl;

  return 0;

  }
}

int Sudoku::menu(){

  cout << "" << endl;
  cout << "Please select any one of the options from the menu below: " << endl;
  cout << "" << endl;
  cout << "1. Start Sudoku Puzzle" << endl;
  cout << "2. Display High Scores" << endl;;
  cout << "3. Exit the Application" << endl;
  cout << "" << endl;
  cout << "Please state you selection: ";

  int userSelect;
  cin >> userSelect;

  menuSelection(userSelect);
}

int main(){

  cout << "Welcome to Sudoku!" << endl;
  Sudoku sudoku;
  sudoku.menu();
  return 0;
}
