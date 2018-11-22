//COP 3503 Final Project.

#ifndef Sudoku_h
#define Sudoku_h
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstddef>
//#include <Windows.h>
#include <vector>
using namespace std;

class Sudoku{
public:
    int menu();

    int menuSelection(int userSelect);

    int selDifficulty();

    int exitPuzzle();

    int highScores();

    void easySudoku1();

    void inputNumber();

    void easySudoku2();

    void easySudoku3();

    int easySudokuMenu();

    int hexaSudoku1();

    void medSudoku1();

    void medSudoku2();

    void medSudoku3();

    void hardSudoku1();

    void hardSudoku2();

    void hardSudoku3();

    void getStartTime();

    void getEndTime();

    int calculateHighscore();

    void saveHighscore(int score);

    void readHighscore();

    void printHighscore();

};
#endif
