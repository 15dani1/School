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
using namespace std;

class Sudoku{
public:
    int menu();

    int menuSelection(int userSelect);

    int selDifficulty();

    int exitPuzzle();

    int highScores();

    int easySudoku1();
};
#endif
