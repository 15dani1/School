#include <iostream>
#include <String>
#include "pa2.h"

using namespace std;

void addProgram(){

    string name;
    int size;
    cout << "Program name - ";
    cin >> name;
    cout << "Program size (KB) - ";
    cin >> size;
    int page;

    if (size % 4 == 0){
      page = size / 4;
    }
    else if (size % 4 !=0){
      page = (size/4)+1;
    }
    cout <<"" <<endl;
    cout << "Program " << name << " added successfully: " << page << " page(s) used.";

}

void killProgram(){}
void Frag(){}
void PrintMem(){}

int main(int argc,char**argv){

  // Takes command line arguments
  string type = argv[0];
  // Creates a new Linked List object and initializes it.
  LinkedList inital;
  int sizeT=0; //Total sizes of all programs.
  int num; //Size of remove program.
  int num2;//Size of added program.
  //Pick an algorithm to allocate the memory in the OS.
//  int fit = inital.fitChoice(type);
  //Exit program if invalid algorithm.
  //if(fit == 2){
    //  exit(0);
  }

  //initial.print();

  //initial.print();

  int y;
  cout << "1. Add Program" <<endl;

  cout << "2. Kill Program" <<endl;
  cout << "3. Fragmentaion" <<endl;
  cout << "4. Print Memory" <<endl;
  cout << "5. Exit" << endl;
  cout <<""<<endl;
  cout << "choice - ";
  cin >> y;
LinkedList initial;
  for (int i = 0; i < 32; i++){
		initial.addNode("Free");
	    }
  /*cout << "linked list:\n";
  for(int i=0; i < 4; i++){
    for(int j=0; j < 8; j++){
      string x = "Free";
      initial.addNode(x);
      }
    }

*/
  switch(y) {
      case 1: addProgram();
      case 2: killProgram();
      case 3: Frag();
      case 4: initial.print();
      case 5: exit(0);
  }
}
