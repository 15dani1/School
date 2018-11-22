//COP 3503 Final Project.

#include "Sudoku.h"

const time_t ctt = time(0);
int highScore1 = 2500;
int highScore2 = 2000;
int highScore3 = 1500;
int highScore4 = 0;
int highScore5 = 0;

int hoursStart = 0;
int minutesStart = 0;
int secondsStart = 0;
int totalSeconds = 0;

int hoursEnd = 0;
int minutesEnd = 0;
int secondsEnd = 0;
int totalSecondsEnd = 0;

int level = 0;

const int rows = 15;
const int columns = 15;


int Sudoku::selDifficulty(){  //method for selection of difficulty

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
    getStartTime();   //starting the timer

    switch(diffChoice){

      case 1:
          level = 1;
          cout << "Easy" << endl;
          int choice;
          cout << "Select Easy 1, 2, or 3 (type Integer): "<<endl;
          cin >> choice;
        /*  int xRan;
	        srand(time(0));
	        xRan = rand() % 3 + 1;
	        cout << xRan;*/

          switch (choice) {
            case 1:
            easySudoku1();  //calling the very first easy sudoku grid
              break;
            case 2:
            easySudoku2();
              break;
            case 3:
            easySudoku3();
              break;
          }
          break;

      case 2:
      level = 2;
          cout << "Medium";
            int xRan2;
            srand(time(0));
            xRan2 = rand() % 3 + 1;
            cout << xRan2;
            switch (xRan2) {
                case 1:
                    medSudoku1();
                    break;
                case 2:
                    medSudoku2();
                    break;
                case 3:
                    medSudoku3();
                    break;
            }
          break;



      case 3:
      level = 3;
          cout << "Hard";
            int xRan3;
            srand(time(0));
            xRan3 = rand() % 3 + 1;
            cout << xRan3;
            switch (xRan3) {
                case 1:
                    hardSudoku1();
                    break;

                case 2:
                    hardSudoku2();
                    break;
                case 3:
                    hardSudoku3();
                    break;
            }
          break;

      case 4:
      level = 4;
          cout << "Bonus(Hexadoku)";
          hexaSudoku1();    //calling the special hexadecimal sudoku
          break;

      case 5:
          menu();
          break;

      default:
        cout << "Invalid choice. Please try again." << endl;
    }

    return 0;
}

int Sudoku::highScores(){    //method for printing out the high scores

  cout << "" << endl;
  cout << "High scores: " << endl;
  printHighscore();
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

int Sudoku::exitPuzzle(){   //method for checking whether the user really wants to exit

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

int Sudoku::menuSelection(int userSelect){  //method which has all the other methods required for the menu

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

int Sudoku::menu(){    //method for the main menu

  cout << "" << endl;
  cout << "Please select any one of the options from the menu below: " << endl;
  cout << "" << endl;
  cout << "1. Start Sudoku Puzzle" << endl;
  cout << "2. Display High Scores" << endl;
  cout << "3. Exit the Application" << endl;
  cout << "" << endl;
  cout << "Please state you selection: ";

  int userSelect;
  cin >> userSelect;

  menuSelection(userSelect);
}

int main(){   //the main method

  cout << "Welcome to Sudoku!" << endl;
  Sudoku sudoku;
  sudoku.menu();
  return 0;
}

void Sudoku::getStartTime(){  //method which gets the local time and starts the timer
  std::string time = asctime(localtime(&ctt));
std::cout<<time[11]<<time[12]<<time[13]<<time[14]<<time[15]<<time[16]<<time[17]<<time[18]<<std::endl;
hoursStart = time[11]*10 + time[12];
minutesStart = time[14]*10 + time[15];
secondsStart = time[17]*10 + time[18];
totalSeconds = hoursStart*3600 + minutesStart*60 + secondsStart;
}

void Sudoku::getEndTime(){  //method which gets the local time and stops the timer
  std::string time = asctime(localtime(&ctt));
std::cout<<time[11]<<time[12]<<time[13]<<time[14]<<time[15]<<time[16]<<time[17]<<time[18]<<std::endl;
hoursEnd = time[11]*10 + time[12];
minutesEnd = time[14]*10 + time[15];
secondsEnd = time[17]*10 + time[18];
totalSecondsEnd = hoursEnd*3600 + minutesEnd*60 + secondsEnd;
}

int Sudoku::calculateHighscore(){
  int score = 1000/((totalSecondsEnd - totalSeconds)/60);
  return score;
}


void Sudoku::saveHighscore(int score){   //method which deals with file manipulation and writes highscores into an external file

    readHighscore();
    if(score >= highScore1){
        highScore5 = highScore4;
        highScore4 = highScore3;
        highScore3 = highScore2;
        highScore2 = highScore1;
        highScore1 = score;
    } else if(score >= highScore2){
        highScore5 = highScore4;
        highScore4 = highScore3;
        highScore3 = highScore2;
        highScore2 = score;
    } else if(score >= highScore3){
        highScore5 = highScore4;
        highScore4 = highScore3;
        highScore3 = score;
    }else if(score >= highScore4){
        highScore5 = highScore4;
        highScore4 = score;
    }else if(score >= highScore5){
        highScore5 = score;
    } else {

    }
    std::ofstream openfile("/Users/yosh/CLionProjects/Sudoku_project/highscoreList");
    if(openfile.is_open()) {
        int i = 0;
        bool randBool = true;
        while (!openfile.eof() && randBool) {
            i++;
            switch (i) {
                case 1:
                    openfile << highScore1 << std::endl;
                    break;
                case 2:
                    openfile << highScore2 << std::endl;
                    break;
                case 3:
                    openfile << highScore3 << std::endl;
                    break;
                case 4:
                    openfile << highScore4 << std::endl;
                    break;
                case 5:
                    openfile << highScore5 << std::endl;
                    break;
                default:
                    randBool = false;
                    break;
            }
        }
    }
}

void Sudoku::readHighscore(){//my code

    std::ifstream openfile("/Users/yosh/CLionProjects/Sudoku_project/highscoreList");

    if(openfile.is_open())
    {

        int i = 0;

        bool randBool2 = true;

        while(!openfile.eof() && randBool2)

        {
            i++;
            switch(i){
                case 1:
                    openfile >> highScore1;
                    break;
                case 2:
                    openfile >> highScore2;
                    break;
                case 3:
                    openfile >> highScore3;
                    break;
                case 4:
                    openfile >> highScore4;
                    break;
                case 5:
                    openfile >> highScore5;
                    break;
                default:
                    randBool2 = false;
                    break;
            }

        }

    }
}

void Sudoku::printHighscore(){

    std::cout<<highScore1<<std::endl;

    std::cout<<highScore2<<std::endl;

    std::cout<<highScore3<<std::endl;

    std::cout<<highScore4<<std::endl;

    std::cout<<highScore5<<std::endl;

}

//easy1


void Sudoku::easySudoku1(){  //the method for the easy sudoku grid



cout << "          Easy Puzzle 1            " << endl;
cout << "" << endl;

/*
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
    */
    string sudokuEasy1 [rows][columns] =

    {
            {" ", " ", " ", "A", "B", "C", " ", "D", "E", "F", " ", "G", "H", "I", " "},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", "|", "9", "1", "8", "|", "7", "4", "5", "|", "6", "3", "2", "|"},
            {" ", "2", "|", "5", "3", "2", "|", "6", "1", "9", "|", "7", "8", "4", "|"},
            {" ", "3", "|", "6", "4", "7", "|", "2", "8", "3", "|", "9", "1", "5", "|"},
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "4", "|", "2", "8", "6", "|", "5", "3", "4", "|", "1", "7", "9", "|"},
            {" ", "5", "|", "3", " ", "4", "|", "1", "7", "8", "|", "2", "5", "6", "|"},
            {" ", "6", "|", "7", "5", "1", "|", "9", "2", "6", "|", "8", "4", "3", "|"}, //Answer is 9.
            {" ", " ", "|", "-", "-", "-", "+", "-", "-", "-", "+", "-", "-", "-", "|"},
            {" ", "7", "|", "1", "6", "9", "|", "4", "5", "7", "|", "3", "2", "8", "|"},
            {" ", "8", "|", "8", "2", "5", "|", "3", "6", "1", "|", "4", "9", "7", "|"},
            {" ", "9", "|", "4", "7", "3", "|", "8", "9", "2", "|", "5", "6", "1", "|"},
            {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

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


for(int i =0; i < 15; i++){
  for(int j = 0; j < 15; j++){

      if (sudokuEasy1[i][j] != " "){
        sudokuEasy1[i][j] = sudokuEasy1[i][j];
      }
  }
}


    for(int i=0; i < 15; i++){

        for(int j=0; j < 15; j++) {

          cout << sudokuEasy1[i][j] << " ";
        }
        cout << endl;
    }
    int easy1MenuOption = 0;
    bool menuActive = true;
    int i = 0;
    while (menuActive){


    std::cout << "Please select an option below" << '\n';
    std::cout << "1. Input number in grid" << '\n';
    std::cout << "2. See if select box has the correct answer" << '\n';  //giving the user a choice to input a number into the grid
    std::cin >> easy1MenuOption;
    switch (easy1MenuOption) {
      case 1:
        i = 0;
            while(sudokuEasy1 != sudokuEasy1Sol && i < 1){
                cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                char letterValue;
                int numberValue;
                cin >> letterValue >> numberValue;

                string position = letterValue + to_string(numberValue);

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
                else if(myLetterVal == 70){        //testing various inputs
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
                checker.push_back("E4"); checker.push_back("E6"); checker.push_back("E7"); checker.push_back("F2");    //making sure pre-set numbers in the grid are not modified
                checker.push_back("F8"); checker.push_back("F9"); checker.push_back("G3"); checker.push_back("G4");
                checker.push_back("G6"); checker.push_back("G7"); checker.push_back("G8"); checker.push_back("H2");
                checker.push_back("H4"); checker.push_back("H6"); checker.push_back("H8"); checker.push_back("H9");
                checker.push_back("I5"); checker.push_back("I9");

                for (unsigned int i = 0; i < checker.size(); i++){
                    if (position == checker[i]){
                        cout << "Error, unable to fill this spot." << endl;
                        easySudoku1();
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
                        if(sudokuEasy1[i][j] == sudokuEasy1Sol[i][j]){       //checking whether the number inputted into the grid is the correct number

                        }

                        else {
                            a = false;
                        }
                    }
                    cout << endl;
                }

                if(a){

                    cout << "Congratulations, you have completed this Easy Sudoku Puzzle!" << endl;
                    getEndTime();
                    saveHighscore(2575);
                    menu();

                }

                else {}
                i++;
            }
      break;
      case 2:
      //  i = 0;
      //  while(sudokuEasy1 != sudokuEasy1Sol && i < 1){
        cout << "Please Enter the Letter and Number Position of the Grid which you would like to check: ";
        char letterValue;
        int numberValue;
        cin >> letterValue >> numberValue;

        string position = letterValue + to_string(numberValue);

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

        string su1 = sudokuEasy1[numberValue][myLetterVal];
        string su2 = sudokuEasy1Sol[numberValue][myLetterVal];
        if (su1 == su2){
          std::cout << "Correct" << '\n';
          cout << "" << endl;
        }
        else
      {
        std::cout << "Incorrect" << '\n';
      }
      break;
      //default:
      //break;
    }
  }
}

  //methods for other grids are structured similarly

  //easy2


  void Sudoku::easySudoku2(){

  cout << "          Easy Puzzle 2            " << endl;
  cout << "" << endl;


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


      for(int i=0; i < 15; i++){

          for(int j=0; j < 15; j++) {

            cout << sudokuEasy2[i][j] << " ";
          }
          cout << endl;
      }
      int easy2MenuOption = 0;
      bool menuActive = true;
      int i = 0;
      while (menuActive){


      std::cout << "Please select an option below" << '\n';
      std::cout << "1. Input number in grid" << '\n';
      std::cout << "2. See if select box has the correct answer" << '\n';
      std::cin >> easy2MenuOption;
      switch (easy2MenuOption) {
        case 1:
          i = 0;
              while(sudokuEasy2 != sudokuEasy2Sol && i < 1){
                  cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                  char letterValue;
                  int numberValue;
                  cin >> letterValue >> numberValue;

                  string position = letterValue + to_string(numberValue);

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
                          easySudoku2();
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
                      getEndTime();
                      saveHighscore(calculateHighscore());
                  }

                  else {}
                  i++;
              }
        break;
        case 2:
          i = 0;
          while(sudokuEasy2 != sudokuEasy2Sol && i < 1){
          cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
          char letterValue;
          int numberValue;
          cin >> letterValue >> numberValue;

          string position = letterValue + to_string(numberValue);

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

          string su1 = sudokuEasy2[numberValue][myLetterVal];
          string su2 = sudokuEasy2Sol[numberValue][myLetterVal];
          if (su1 == su2){
            std::cout << "Correct" << '\n';
          }
          else
        {
          std::cout << "Incorrect" << '\n';
        }
  }
          break;
        default:
        break;
      }
    }
    }

    //easy3


    void Sudoku::easySudoku3(){

    cout << "          Easy Puzzle 3            " << endl;
    cout << "" << endl;


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


        for(int i=0; i < 15; i++){

            for(int j=0; j < 15; j++) {

              cout << sudokuEasy3[i][j] << " ";
            }
            cout << endl;
        }
        int easy3MenuOption = 0;
        bool menuActive = true;
        int i = 0;
        while (menuActive){


        std::cout << "Please select an option below" << '\n';
        std::cout << "1. Input number in grid" << '\n';
        std::cout << "2. See if select box has the correct answer" << '\n';
        std::cin >> easy3MenuOption;
        switch (easy3MenuOption) {
          case 1:
            i = 0;
                while(sudokuEasy3 != sudokuEasy3Sol && i < 1){
                    cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                    char letterValue;
                    int numberValue;
                    cin >> letterValue >> numberValue;

                    string position = letterValue + to_string(numberValue);

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
                            easySudoku3();
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
                        getEndTime();
                        saveHighscore(calculateHighscore());
                    }

                    else {}
                    i++;
                }
          break;
          case 2:
            i = 0;
            while(sudokuEasy3 != sudokuEasy3Sol && i < 1){
            cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
            char letterValue;
            int numberValue;
            cin >> letterValue >> numberValue;

            string position = letterValue + to_string(numberValue);

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

            string su1 = sudokuEasy3[numberValue][myLetterVal];
            string su2 = sudokuEasy3Sol[numberValue][myLetterVal];
            if (su1 == su2){
              std::cout << "Correct" << '\n';
            }
            else
          {
            std::cout << "Incorrect" << '\n';
          }
    }
            break;
          default:
          break;
        }
      }
      }
    //hard1


    void Sudoku::hardSudoku1(){


    cout << "          Hard Puzzle 1            " << endl;
    cout << "" << endl;


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


        for(int i=0; i < 15; i++){

            for(int j=0; j < 15; j++) {

              cout << sudokuHard1[i][j] << " ";
            }
            cout << endl;
        }
        int hard1MenuOption = 0;
        bool menuActive = true;
        int i = 0;
        while (menuActive){


        std::cout << "Please select an option below" << '\n';
        std::cout << "1. Input number in grid" << '\n';
        std::cout << "2. See if select box has the correct answer" << '\n';
        std::cin >> hard1MenuOption;
        switch (hard1MenuOption) {
          case 1:
            i = 0;
                while(sudokuHard1 != sudokuHard1Sol && i < 1){
                    cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                    char letterValue;
                    int numberValue;
                    cin >> letterValue >> numberValue;

                    string position = letterValue + to_string(numberValue);

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
                            hardSudoku1();
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
                        getEndTime();
                        saveHighscore(calculateHighscore());
                    }

                    else {}
                    i++;
                }
          break;
          case 2:
            i = 0;
            while(sudokuHard1 != sudokuHard1Sol && i < 1){
            cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
            char letterValue;
            int numberValue;
            cin >> letterValue >> numberValue;

            string position = letterValue + to_string(numberValue);

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

            string su1 = sudokuHard1[numberValue][myLetterVal];
            string su2 = sudokuHard1Sol[numberValue][myLetterVal];
            if (su1 == su2){
              std::cout << "Correct" << '\n';
            }
            else
          {
            std::cout << "Incorrect" << '\n';
          }
    }
            break;
          default:
          break;
        }
      }
      }
    //hard2



    void Sudoku::hardSudoku2(){


    cout << "          Hard Puzzle 2            " << endl;
    cout << "" << endl;


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


        for(int i=0; i < 15; i++){

            for(int j=0; j < 15; j++) {

              cout << sudokuHard2[i][j] << " ";
            }
            cout << endl;
        }
        int hard2MenuOption = 0;
        bool menuActive = true;
        int i = 0;
        while (menuActive){


        std::cout << "Please select an option below" << '\n';
        std::cout << "1. Input number in grid" << '\n';
        std::cout << "2. See if select box has the correct answer" << '\n';
        std::cin >> hard2MenuOption;
        switch (hard2MenuOption) {
          case 1:
            i = 0;
                while(sudokuHard2 != sudokuHard2Sol && i < 1){
                    cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                    char letterValue;
                    int numberValue;
                    cin >> letterValue >> numberValue;

                    string position = letterValue + to_string(numberValue);

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
                            hardSudoku2();
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
                        getEndTime();
                        saveHighscore(calculateHighscore());
                    }

                    else {}
                    i++;
                }
          break;
          case 2:
            i = 0;
            while(sudokuHard2 != sudokuHard2Sol && i < 1){
            cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
            char letterValue;
            int numberValue;
            cin >> letterValue >> numberValue;

            string position = letterValue + to_string(numberValue);

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

            string su1 = sudokuHard2[numberValue][myLetterVal];
            string su2 = sudokuHard2Sol[numberValue][myLetterVal];
            if (su1 == su2){
              std::cout << "Correct" << '\n';
            }
            else
          {
            std::cout << "Incorrect" << '\n';
          }
    }
            break;
          default:
          break;
        }
      }
      }

    //hard3


    void Sudoku::hardSudoku3(){

    cout << "          Hard Puzzle 3            " << endl;
    cout << "" << endl;


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


        for(int i=0; i < 15; i++){

            for(int j=0; j < 15; j++) {

              cout << sudokuHard3[i][j] << " ";
            }
            cout << endl;
        }
        int hard3MenuOption = 0;
        bool menuActive = true;
        int i = 0;
        while (menuActive){


        std::cout << "Please select an option below" << '\n';
        std::cout << "1. Input number in grid" << '\n';
        std::cout << "2. See if select box has the correct answer" << '\n';
        std::cin >> hard3MenuOption;
        switch (hard3MenuOption) {
          case 1:
            i = 0;
                while(sudokuHard3 != sudokuHard3Sol && i < 1){
                    cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                    char letterValue;
                    int numberValue;
                    cin >> letterValue >> numberValue;

                    string position = letterValue + to_string(numberValue);

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
                            hardSudoku3();
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
                        getEndTime();
                        saveHighscore(calculateHighscore());
                    }

                    else {}
                    i++;
                }
          break;
          case 2:
            i = 0;
            while(sudokuHard3 != sudokuHard3Sol && i < 1){
            cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
            char letterValue;
            int numberValue;
            cin >> letterValue >> numberValue;

            string position = letterValue + to_string(numberValue);

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

            string su1 = sudokuHard3[numberValue][myLetterVal];
            string su2 = sudokuHard3Sol[numberValue][myLetterVal];
            if (su1 == su2){
              std::cout << "Correct" << '\n';
            }
            else
          {
            std::cout << "Incorrect" << '\n';
          }
    }
            break;
          default:
          break;
        }
      }
      }
    //medium1

    void Sudoku::medSudoku1(){

    cout << "          Medium Puzzle 1            " << endl;
    cout << "" << endl;


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
                {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},    };


    for(int i =0; i < 15; i++){
      for(int j = 0; j < 15; j++){

          if (sudokuMed1[i][j] != " "){
            sudokuMed1[i][j] = sudokuMed1[i][j];
          }
      }
    }


        for(int i=0; i < 15; i++){

            for(int j=0; j < 15; j++) {

              cout << sudokuMed1[i][j] << " ";
            }
            cout << endl;
        }
        int med1MenuOption = 0;
        bool menuActive = true;
        int i = 0;
        while (menuActive){


        std::cout << "Please select an option below" << '\n';
        std::cout << "1. Input number in grid" << '\n';
        std::cout << "2. See if select box has the correct answer" << '\n';
        std::cin >> med1MenuOption;
        switch (med1MenuOption) {
          case 1:
            i = 0;
                while(sudokuMed1 != sudokuMed1Sol && i < 1){
                    cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                    char letterValue;
                    int numberValue;
                    cin >> letterValue >> numberValue;

                    string position = letterValue + to_string(numberValue);

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
                            medSudoku1();
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
                        getEndTime();
                        saveHighscore(calculateHighscore());
                    }

                    else {}
                    i++;
                }
          break;
          case 2:
            i = 0;
            while(sudokuMed1 != sudokuMed1Sol && i < 1){
            cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
            char letterValue;
            int numberValue;
            cin >> letterValue >> numberValue;

            string position = letterValue + to_string(numberValue);

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

            string su1 = sudokuMed1[numberValue][myLetterVal];
            string su2 = sudokuMed1Sol[numberValue][myLetterVal];
            if (su1 == su2){
              std::cout << "Correct" << '\n';
            }
            else
          {
            std::cout << "Incorrect" << '\n';
          }
    }
            break;
          default:
          break;
        }
      }
      }
      //medium2

      void Sudoku::medSudoku2(){

          cout << "          Medium Puzzle 2            " << endl;
          cout << "" << endl;


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


          for(int i=0; i < 15; i++){

              for(int j=0; j < 15; j++) {

                  cout << sudokuMed2[i][j] << " ";
              }
              cout << endl;
          }
          int med2MenuOption = 0;
          bool menuActive = true;
          int i = 0;
          while (menuActive){


              std::cout << "Please select an option below" << '\n';
              std::cout << "1. Input number in grid" << '\n';
              std::cout << "2. See if select box has the correct answer" << '\n';
              std::cin >> med2MenuOption;
              switch (med2MenuOption) {
              case 1:
                  i = 0;
                  while(sudokuMed2 != sudokuMed2Sol && i < 1){
                      cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                      char letterValue;
                      int numberValue;
                      cin >> letterValue >> numberValue;

                      string position = letterValue + to_string(numberValue);

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

                      checker.push_back("A3");
                                    checker.push_back("A5");
                                    checker.push_back("A8");
                                    checker.push_back("A9");
                                    checker.push_back("B1");
                                    checker.push_back("B4");
                                    checker.push_back("B7");
                                    checker.push_back("B8");
                                    checker.push_back("C7");
                                    checker.push_back("C9");
                                    checker.push_back("D1");
                                    checker.push_back("D4");
                                    checker.push_back("D6");
                                    checker.push_back("D8");
                                    checker.push_back("E2");
                                    checker.push_back("E3");
                                    checker.push_back("E7");
                                    checker.push_back("E8");
                                    checker.push_back("F2");
                                    checker.push_back("F4");
                                    checker.push_back("F6");
                                    checker.push_back("F9");
                                    checker.push_back("G1");
                                    checker.push_back("G3");
                                    checker.push_back("H2");
                                    checker.push_back("H3");
                                    checker.push_back("H6");
                                    checker.push_back("H9");
                                    checker.push_back("I1");
                                    checker.push_back("I2");
                                    checker.push_back("I5");
                                    checker.push_back("I7");
                      for (unsigned int i = 0; i < checker.size(); i++){
                          if (position == checker[i]){
                              cout << "Error, unable to fill this spot." << endl;
                              medSudoku2();
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
                          getEndTime();
                          saveHighscore(calculateHighscore());
                      }

                      else {}
                      i++;
                  }
                  break;
              case 2:
                  i = 0;
                  while(sudokuMed2 != sudokuMed2Sol && i < 1){
                      cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
                      char letterValue;
                      int numberValue;
                      cin >> letterValue >> numberValue;

                      string position = letterValue + to_string(numberValue);

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

                      string su1 = sudokuMed2[numberValue][myLetterVal];
                      string su2 = sudokuMed2Sol[numberValue][myLetterVal];
                      if (su1 == su2){
                          std::cout << "Correct" << '\n';
                      }
                      else
                      {
                          std::cout << "Incorrect" << '\n';
                      }
                  }
                  break;
              default:
                  break;
              }
          }
      }

      //medium3
      void Sudoku::medSudoku3(){

          cout << "          Medium Puzzle 3            " << endl;
          cout << "" << endl;


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
                  {" ", " ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},    };

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


          for(int i=0; i < 15; i++){

              for(int j=0; j < 15; j++) {

                  cout << sudokuMed3[i][j] << " ";
              }
              cout << endl;
          }
          int med3MenuOption = 0;
          bool menuActive = true;
          int i = 0;
          while (menuActive){


              std::cout << "Please select an option below" << '\n';
              std::cout << "1. Input number in grid" << '\n';
              std::cout << "2. See if select box has the correct answer" << '\n';
              std::cin >> med3MenuOption;
              switch (med3MenuOption) {
              case 1:
                  i = 0;
                  while(sudokuMed3 != sudokuMed3Sol && i < 1){
                      cout << "Please Enter the Letter and Number Position of the Grid in which you would like to fill a value (Ex: A5): ";
                      char letterValue;
                      int numberValue;
                      cin >> letterValue >> numberValue;

                      string position = letterValue + to_string(numberValue);

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
                              medSudoku3();
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
                          getEndTime();
                          saveHighscore(calculateHighscore());
                      }

                      else {}
                      i++;
                  }
                  break;
              case 2:
                  i = 0;
                  while(sudokuMed3 != sudokuMed3Sol && i < 1){
                      cout << "Please Enter the Letter and Number Position of the Grid which you would like to check";
                      char letterValue;
                      int numberValue;
                      cin >> letterValue >> numberValue;

                      string position = letterValue + to_string(numberValue);

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

                      string su1 = sudokuMed3[numberValue][myLetterVal];
                      string su2 = sudokuMed3Sol[numberValue][myLetterVal];
                      if (su1 == su2){
                          std::cout << "Correct" << '\n';
                      }
                      else
                      {
                          std::cout << "Incorrect" << '\n';
                      }
                  }
                  break;
              default:
                  break;
              }
          }
      }
//Hexadoku


int Sudoku::hexaSudoku1(){

const int rowss = 22;
const int columnss = 23;

cout << "This is Hexadecimal Sudoku! These are the numbers that you will use            " << endl;
cout << "        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F                                 " << endl;
cout << "" << endl;

    string hexaSudokuSol [rowss][columnss] =
    {
            {" ", " ", "  ", "A", "B", "C", "D", "-", "E", "F", "G", "H", "-", "I", "J", "K", "L", "-", "M", "N", "O", "P", " "},
            {" ", " ", " +", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", " |", "B", "7", "8", "5", "|", "E", "6", "0", "A", "|", "4", "D", "2", "C", "|", "1", "3", "F", "9", "|"},
            {" ", "2", " |", "A", "F", "0", "1", "|", "5", "9", "2", "8", "|", "B", "3", "E", "6", "|", "D", "C", "4", "7", "|"},
            {" ", "3", " |", "D", "4", "9", "2", "|", "C", "B", "3", "7", "|", "A", "0", "1", "F", "|", " ", "8", "E", "6", "|"},
            {" ", "4", " |", "C", "3", "E", "6", "|", "D", "4", "F", "1", "|", "5", "7", "9", "8", "|", "C", "0", "B", "A", "|"},
            {" ", " ", " |", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "|"},
            {" ", "5", " |", "7", "B", "C", "A", "|", "3", "0", "4", "2", "|", "9", "F", "D", "1", "|", "8", "E", "6", "5", "|"},
            {" ", "6", " |", "3", "5", "6", "4", "|", "F", "E", "9", "D", "|", "0", "8", "C", "7", "|", "B", "A", "1", "2", "|"},
            {" ", "7", " |", "E", "9", "1", "F", "|", "8", "A", "7", "C", "|", "2", "6", "B", "5", "|", "3", "4", "0", "D", "|"},
            {" ", "8", " |", "0", "2", "D", "8", "|", "B", "1", "6", "5", "|", "3", "A", "4", "E", "|", "C", "7", "9", "F", "|"},
            {" ", " ", " |", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "|"},
            {" ", "9", " |", "9", "6", "7", "0", "|", "4", "3", "D", "F", "|", "1", "C", "8", "B", "|", "A", "2", "5", "E", "|"},
            {" ","10", "|", "4", "C", "A", "B", "|", "6", "8", "5", "E", "|", "F", "9", "0", "2", "|", "7", "1", "D", "3", "|"},
            {" ","11", "|", "F", "8", "3", "D", "|", "2", "7", "1", "0", "|", "6", "E", "5", "A", "|", "4", "9", "C", "B", "|"},
            {" ","12", "|", "5", "1", "2", "E", "|", "A", "C", "B", "9", "|", "7", "4", "3", "D", "|", "F", "6", "8", "0", "|"},
            {" ","  ", "|", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "|"},
            {" ","13", "|", "6", "0", "B", "C", "|", "7", "D", "A", "3", "|", "E", "1", "F", "4", "|", "9", "5", "2", "8", "|"},
            {" ","14", "|", "2", "A", "5", "3", "|", "9", "F", "8", "4", "|", "C", "B", "6", "0", "|", "E", "D", "7", "1", "|"},
            {" ","15", "|", "8", "E", "F", "9", "|", "1", "5", "C", "6", "|", "D", "2", "7", "3", "|", "0", "B", "A", "4", "|"},
            {" ","16", "|", "1", "D", "4", "7", "|", "0", "2", "E", "B", "|", "8", "5", "A", "9", "|", "6", "F", "3", "C", "|"},
            {" ","  ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };

    string hexaSudoku [rowss][columnss] =
    {
            {" ", " ", "  ", "A", "B", "C", "D", "-", "E", "F", "G", "H", "-", "I", "J", "K", "L", "-", "M", "N", "O", "P", " "},
            {" ", " ", " +", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
            {" ", "1", " |", " ", "7", " ", "5", "|", " ", " ", " ", " ", "|", " ", "D", " ", " ", "|", "1", " ", " ", " ", "|"},
            {" ", "2", " |", "A", "F", "0", " ", "|", " ", " ", " ", " ", "|", " ", " ", "E", " ", "|", " ", " ", "4", "7", "|"},
            {" ", "3", " |", " ", " ", " ", " ", "|", "C", "B", "3", " ", "|", "A", " ", "1", " ", "|", " ", "8", " ", " ", "|"},
            {" ", "4", " |", " ", "3", " ", " ", "|", " ", " ", " ", "1", "|", " ", " ", "9", " ", "|", "C", " ", "B", " ", "|"},
            {" ", " ", " |", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "|"},
            {" ", "5", " |", "7", "B", " ", "A", "|", " ", " ", " ", "2", "|", "9", " ", " ", " ", "|", " ", "E", " ", "5", "|"},
            {" ", "6", " |", "3", " ", "6", " ", "|", " ", " ", "9", " ", "|", " ", "8", " ", "7", "|", " ", " ", "1", "2", "|"},
            {" ", "7", " |", " ", " ", " ", "F", "|", "8", "A", " ", "C", "|", " ", "6", "B", "5", "|", " ", " ", " ", " ", "|"},
            {" ", "8", " |", " ", "2", " ", " ", "|", " ", " ", " ", "5", "|", " ", "A", "4", " ", "|", "C", " ", "9", " ", "|"},
            {" ", " ", " |", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "|"},
            {" ", "9", " |", " ", "6", " ", "0", "|", " ", "3", "D", " ", "|", "1", " ", " ", " ", "|", " ", " ", "5", " ", "|"},
            {" ","10", "|", " ", " ", " ", " ", "|", "6", "8", "5", " ", "|", "F", " ", "0", "2", "|", "7", " ", " ", " ", "|"},
            {" ","11", "|", "F", "8", " ", " ", "|", "2", " ", "1", " ", "|", " ", "E", " ", " ", "|", " ", "9", " ", "B", "|"},
            {" ","12", "|", "5", " ", "2", " ", "|", " ", " ", " ", "9", "|", "7", " ", " ", " ", "|", "F", " ", "8", "0", "|"},
            {" ","  ", "|", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "+", "-", "-", "-", "-", "|"},
            {" ","13", "|", " ", "0", " ", "C", "|", " ", "D", " ", " ", "|", "E", "1", " ", " ", "|", " ", " ", "2", " ", "|"},
            {" ","14", "|", " ", " ", " ", " ", "|", " ", "F", " ", "4", "|", " ", "B", "6", "0", "|", " ", " ", " ", " ", "|"},
            {" ","15", "|", "8", "E", " ", " ", "|", " ", "5", " ", " ", "|", " ", " ", " ", " ", "|", " ", "B", "A", "4", "|"},
            {" ","16", "|", "1", " ", "4", " ", "|", " ", " ", "E", " ", "|", " ", " ", " ", " ", "|", "6", " ", "3", " ", "|"},
            {" ","  ", "+", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "+"},
    };


    for(int i=0; i < 22; i++){

        for(int j=0; j < 23; j++) {

          cout << hexaSudoku[i][j] << " ";
        }
        cout << endl;
    }


while(hexaSudoku != hexaSudokuSol){
cout << endl;
cout << "Please Enter the Letter Position of the Grid in which you would like to fill a value (Ex: B): ";
char letterValue;
cin >> letterValue;

int myLetterVal = (int)letterValue;
//determines letter values from ascii table
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
  myLetterVal = 6;
}
else if(myLetterVal == 69){
  myLetterVal = 8;
}
else if(myLetterVal == 70){
  myLetterVal = 9;
}
else if(myLetterVal == 71){
  myLetterVal = 10;
}
else if(myLetterVal == 72){
  myLetterVal = 11;
}
else if(myLetterVal == 73){
  myLetterVal = 13;
}
else if(myLetterVal == 74){
  myLetterVal = 14;
}
else if(myLetterVal == 75){
  myLetterVal = 15;
}
else if(myLetterVal == 76){
  myLetterVal = 16;
}
else if(myLetterVal == 77){
  myLetterVal = 18;
}
else if(myLetterVal == 78){
  myLetterVal = 19;
}
else if(myLetterVal == 79){
  myLetterVal = 20;
}
else if(myLetterVal == 80){
  myLetterVal = 21;
}
else {
  cout << "Error Invalid Letter" << endl;
}

cout << "";
cout << "Please Enter the Number Position of the Grid in which you would like to fill a value (Ex: 5): ";
int numberValue;
cin >> numberValue;

if (numberValue >= 1 && numberValue <=4){

    numberValue = numberValue + 1;
}
else if(numberValue > 4 && numberValue <=8){
    numberValue = numberValue + 2;
}

else if(numberValue > 8 && numberValue <= 12){

  numberValue = numberValue + 3;
}

else if(numberValue > 12 && numberValue <= 16){

  numberValue = numberValue + 4;
}
else {
  cout << "Error Invalid Number" << endl;
}

cout << "";
cout << "Please Enter the Sudoku number in the desired position: ";
string sudokuValue;
cin >> sudokuValue;

cout << "" << endl;

hexaSudoku[numberValue][myLetterVal] = sudokuValue;

bool a = true;
for(int i=0; i < 22; i++){

    for(int j=0; j < 23; j++) {

      cout << hexaSudoku[i][j] << " ";
      if(hexaSudoku[i][j] == hexaSudokuSol[i][j]){

      }

      else {
        a = false;
      }
    }
    cout << endl;
    }

    if(a){

      cout << "Congratulations, you have completed this Hexadoku Puzzle!" << endl;
      return 0;
    }

    else {}

    }
}
