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
#include <Windows.h>
#include <vector>
using namespace std;

class Sudoku{
public:
    int menu();

    int menuSelection(int userSelect);

    int selDifficulty();

    int exitPuzzle();

    int highScores();

    int easySudoku1();

    int easySudoku2();

    int easySudoku3();

    int easySudokuMenu();

    int hexaSudoku1();

    int medSudoku1();

    int medSudoku2();

    int medSudoku3();

    int hardSudoku1();

    int hardSudoku2();

    int hardSudoku3();

};
#endif
