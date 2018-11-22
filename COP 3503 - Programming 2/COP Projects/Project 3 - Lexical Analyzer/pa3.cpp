//Rahul Dani (9013-1693) - COP 3503 Project 3 - Lexical Analyzer.
//This Program will analyze the source code from the input file and extract
//all the tokens such as: keywords, identifiers, constants, operators, and delimiters.
//This is the pa3.cpp file.
//Citation: https://www.geeksforgeeks.org/stackpush-stackpop-c-stl/.

#include "pa3.h"
//Initializing the List Objects
List list;
List keywords;
List identifiers;
List constants;
List operators;
List delimiters;
List errors;

//Starts List with NULL.
List::List()    {
    start = NULL;
    curr = NULL;
    temp = NULL;
}
int main() {
    //Allows user to enter input file name.
    string userTxt;
    cout << "Please enter the name of the input file (with .txt at the end): ";
    cin >> userTxt;
    cout << "" << endl;

    //If-Else Statement to test if a text file exists, and then runs the program if it exists.
    ifstream inputFile;
    inputFile.open(userTxt);
    if(inputFile.good())   {
        string line;
        while(!inputFile.eof())   {
             inputFile >> line;
             list.RemoveCharacters(line);
      }
      inputFile.close();
    }
    else    {
        cout << "Error, non-existent file." << endl;
        return 0;
    }
    cout << "The depth of the nested loop(s) is " << list.checkForNested() << endl << endl;
    list.PushBack();
    string keyword = keywords.PrintList();
    cout << "Keywords: " << keyword << endl;
    string identifier = identifiers.PrintList();
    cout << "Indentifiers: " << identifier << endl;
    string constant = constants.PrintList();
    cout << "Constants: " << constant << endl;
    string ops = operators.PrintList();
    cout << "Operators: " << ops << endl;
    string delimiter = delimiters.PrintList();
    cout << "Delimiters: " << delimiter << endl << endl;
    string error = errors.PrintList();
    if(error == ""){
      error = "NA";
    }
    cout << "Syntax Error(s): " << error << endl;
    return 0;
}

//This function tests whether "check" is a keyword
bool List::CheckForKeyword(string check)   {
    if(!(curr->data).compare("FOR") ||
       !(curr->data).compare("BEGIN") ||
       !(curr->data).compare("END")) {
        return true;
    }
    return false;
}

//This function tests how many nested loops exist
int List::checkForNested() {
    int count = 0;
    int max = 0;
    curr = start;

    if(start != NULL)   {
        while(curr->next != NULL) {
            if(CheckForUpper(curr->data))   {
                count++;
                curr = curr->next;
                while(!(CheckForUpper(curr->data) || curr->next == NULL))   {
                    if(CheckForNumber(curr->data) && CheckForDelimiter(curr->next->data))   {
                        count -= 3;
                    }
                    curr = curr->next;
                }
            }
            else    {
                while(!(CheckForUpper(curr->data) || curr->next == NULL))   {
                    curr = curr->next;

                }
            }
            //Find max number
            if(count > max) {
                max = count;
            }
        }
    }

    if(max == 0){
    return max;
  }
    else if(max == 2){
    return max - 1;
  }
}

//This function tests whether "check" is an operator
bool List::CheckForOperator(string check) {
    char c = '0';
    int num = 0;
    int length = check.length();
    bool n = false;
    if(length == 1) {
        c = check[0];
        num = (int)c;
        if(num == 42 || num == 43 || num == 45 || num == 47 || num == 61) {
            n = true;
        }
        else    {
            return false;
        }
    }
    else if(length == 2)    {
        if(check[0]==check[1])   {
            for(int i = 0; i < length; i++) {
                c = check[i];
                num = (int)c;
                if(num == 61 || num == 43 || num == 45)   {
                    n = true;
                }
                else{
                    return false;
                }
            }
        }
        else    {
               return false;
        }
    }
    return n;
}

//This function tests whether "check" is a delimiter
bool List::CheckForDelimiter(string check) {
    if(!(check).compare(",") || !(check).compare(";")) {
        return true;
    }
    return false;
}

//This function returns whether "check" is currently in the list
bool List::CheckExist(string check) {
    bool exist = false;
    curr = start;
    while(curr != NULL) {
        //Checking if the data referenced in the node is equivalent to the "check" program
        if((curr->data).compare(check) == 0) {
            exist = true;
        }
        curr = curr->next;
    }
    curr = start;
    return exist; //returns true if check is in the Linked List
}

//This function tests whether "check" is a character string with characters from 'a-z'.
bool List::CheckForLetter(string check)    {
    char c = '0';
    int num = 0;
    int length = check.length();
    bool n = false;
    for(int i = 0; i < length; i++) {
        c = check[i];
        num = (int)c;
        if(num < 123 && num > 96)   {
            n = true;
        }
        else{
            return false;
        }
    }
    return n;
}

//This function tests whether "check" value is a number.
bool List::CheckForNumber(string check)    {
    char c = '0';
    int num = 0;
    int length = check.length();
    bool n = false;
    for(int i = 0; i < length; i++) {
        c = check[i];
        num = (int)c;
        if(num < 59 && num > 47)   {
            n = true;
        }
        else{
            return false;
        }
    }
    return n;
}

//This function tests whether "check" value is all Uppercase
bool List::CheckForUpper(string check) {
    char c = '0';
    int num = 0;
    int length = check.length();
    bool n = false;
    for(int i = 0; i < length; i++) {
        c = check[i];
        num = (int)c;
        if(num < 91 && num > 64)   {
            n = true;
        }
        else{
            return false;
        }
    }
    return n;
}
//This function pops the information from the stack
void List::Pop()    {
    //Follows the 'Last In First Out' stack structure, so the last inputted item is the first to exit
    start = start->next;
}
//This function prints a list
string List::PrintList()   {
    string output = "";
    //Loops through the Linked List
    curr = start;
    while(curr != NULL) {
        output += curr->data + " ";
        curr = curr->next;
    }
    return output;
}
//This method inserts the "space" at the top of the stack
void List::Push(string space) {
    //Initialize node pointer, pointer to the next node, and the node's data
    LinkedList* nod = new LinkedList;
    nod->next = NULL; //The Linked List should always end in NULL
    nod->data = space;
    temp = start;
    start = nod;
    nod->next = temp;
}
//This method takes the main stack and separates it into smaller more specific lists
void List::PushBack() {
    curr = start;
    while(curr != NULL) {
        if(CheckForKeyword(curr->data)) {
            if(!keywords.CheckExist(curr->data)) {
                keywords.Push(curr->data);
            }
        }
        else if(list.CheckForLetter(curr->data))   {
            if(!identifiers.CheckExist(curr->data)) {
                identifiers.Push(curr->data);
            }
        }
        else if(list.CheckForNumber(curr->data))   {
            if(!constants.CheckExist(curr->data)) {
                constants.Push(curr->data);
            }
        }
        else if(CheckForDelimiter(curr->data))   {
            if(!delimiters.CheckExist(curr->data)) {
                delimiters.Push(curr->data);
            }
        }
        else if(list.CheckForOperator(curr->data))   {
            if(!operators.CheckExist(curr->data)) {
                operators.Push(curr->data);
            }
        }
        else    {
            if(!errors.CheckExist(curr->data)) {
                errors.Push(curr->data);
            }
        }
        //removes item from list
        list.Pop();
        curr = start;
    }
}
//This function deletes a user-specified program from the list
void List::RemoveCharacters(string line)   {
    int length = line.length();
    int i = 0;
    for(i = 0; i < length; i++)   {
        if(line.at(i) == (')') || line.at(i) == ('(')) {
            line = line.erase(i, 1); //erase parentheses
            i--;
        }
        else if(line.at(i) == (';') || line.at(i) == (',') || line.at(i) == ('=')) {
            string newLine = "";
            for(int j = 0; j < i; j++) {
                newLine += line.at(j);
            }
            list.Push(newLine); //Push string before the above characters, so they aren't connected
            string c = "";
            c += line.at(i);
            list.Push(c); //Push one of the characters from above
            newLine = "";
            for(int k = i+1; k < length; k++) {
                newLine += line.at(k);
            }
            line = newLine;
            i++;
        }
        length = line.length(); //Reassigns line length
    }
    if(line != "") {
        list.Push(line); //Pushes the remaining part of the line
    }
}
