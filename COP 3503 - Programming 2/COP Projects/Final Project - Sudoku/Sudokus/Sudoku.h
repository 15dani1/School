//COP 3503 Final Project.

//Imports all the needed Libraries.
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

// Accessible anywhere in the file.
public:
    //Method for the Menu.
    int menu();

    //User selects options from Menu.
    int menuSelection(int userSelect);

    //Method for Difficulty selection.
    int selDifficulty();

    //Method for exiting the puzzle.
    int exitPuzzle();

    //Method for checking High scores.
    int highScores();

    //Method Easy Sudoku 1.
    int easySudoku1();

    //Method Easy Sudoku 2.
    int easySudoku2();

    //Method Easy Sudoku 3.
    int easySudoku3();

    //Method for the easy Sudoku Menu.
    int easySudokuMenu();

    //Method for HexaSudoku.
    int hexaSudoku1();

    //Method Medium Sudoku 1.
    int medSudoku1();

    //Method Medium Sudoku 2.
    int medSudoku2();

    //Method Medium Sudoku 3.
    int medSudoku3();

    //Method Hard Sudoku 1.
    int hardSudoku1();

    //Method Hard Sudoku 2.
    int hardSudoku2();

    //Method Hard Sudoku 3.
    int hardSudoku3();

};
#endif
