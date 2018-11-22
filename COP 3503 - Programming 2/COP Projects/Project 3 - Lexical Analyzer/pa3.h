//Rahul Dani (9013-1693) - COP 3503 Project 3 - Lexical Analyzer.
//This Program will analyze the source code from the input file and extract
//all the tokens such as: keywords, identifiers, constants, operators, and delimiters.
//This is the pa3 header file.

#ifndef pa3_h
#define pa3_h
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstddef>
using namespace std;

//This class deals with initializing the variables dealing with nodes.
class LinkedList {
public:
    string data;
    LinkedList* next;
};

//This class deals with initializing the nodes in the Linked List and the functions that alter the data within it.
class List {
private:
    LinkedList* start;
    LinkedList* curr;
    LinkedList* temp;
public:
    List();
    //This function tests how many nested loops exist
    int checkForNested();
    //This function tests whether 'check' is a delimiter
    bool CheckForDelimiter(string check);
    //This function returns whether "check" is currently in the list
    bool CheckExist(string check);
    //This function tests whether 'check' is a keyword
    bool CheckForKeyword(string check);
    //This function tests whether "space' is a character string with characters from 'a-z'
    bool CheckForLetter(string check);
    //This function tests whether "space' is a numerical value
    bool CheckForNumber(string check);
    //This function tests whether "space' is an operator
    bool CheckForOperator(string check);
    //This function tests whether 'space' is all Uppercase
    bool CheckForUpper(string check);
    //This function pops the information from the stack
    void Pop();
    //This function prints a list
    string PrintList();
    //This method inserts the 'space' at the top of the stack
    void Push(string check);
    //This method takes the main stack and separates it into smaller more specific lists
    void PushBack();
    //This function deletes a user-specified program from the list
    void RemoveCharacters(string line);
};
#endif
