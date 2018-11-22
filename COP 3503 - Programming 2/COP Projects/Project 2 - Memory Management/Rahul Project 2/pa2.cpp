
//Rahul Dani (9013-1693)- COP 3503 Project 2 - OS Memory Allocation
//This Project will emulate the OS's responsibility of allocating
//-memory to certain programs using best and worst fit algorithms.
//This is the pa2 cpp file.

#include <iostream>
#include "pa2.h"
using namespace std;

int main(){

  cout << "Pick an algorithm to allocate the memory in the OS, best or worst." << endl;
	string type;
	cin >> type;
  int userSelect = 0;
  string name;
  int size;

  LinkedList LinkedList; // Creates a new Linked List object and initializes it.
  int sizeTotal=0;  //Total sizes of all programs.
  int remsize; //Size of the remove program.
  int addsize;//Size of added program.

  int fit = LinkedList.fitType(type); //Pick an algorithm to allocate the memory in the OS.

  if(fit == 2){ //Exit program if invalid algorithm.
      return(0);
    }

  for (int i = 0; i < 31; i++){ //Initializes the Linked List with 32 nodes that "Free" is stored in.
      LinkedList.makeNode("Free");
    }

while (userSelect != 5){ //User's desired selection.
  cout << "" << endl;
  cout << "1. Add Program" <<endl;
  cout << "2. Kill Program" <<endl;
  cout << "3. Fragmentation" <<endl;
  cout << "4. Print Memory" <<endl;
  cout << "5. Exit" << endl;
  cout <<""<<endl;
  cout << "choice - ";
  cin >> userSelect;

  switch(userSelect) {
      case 1: //If user wishes to add a program.
        cout << "Program name - ";
        cin >> name;
        cout << "Program size (KB) - ";
        cin >> size;
        cout << "" <<endl;
        size = LinkedList.validInput(size); //Input validation
        if (size%4 == 0){ //Size of Program.
					addsize = (size/4)*4;
				}
				else{
					addsize= (size/4 + 1)*4;
				}

				sizeTotal =sizeTotal + addsize; //Check if not enough memory.
				if (128 < sizeTotal){
					cout<< "Error, Not enough memory for Program " << name << endl;
					sizeTotal = sizeTotal - size;
          
				}

				else if(fit==1){ //Best fit algorithm.
				LinkedList.bestFit(name, size);
				}

				else if(fit==0){ //Worst fit algorithm.
					LinkedList.worstFit(name, size);
				}
        break;

      case 2: //If user wishes to remove a program.
        cout << "Program name -";
        cin >> name;
        cout << "" << endl;
        remsize = LinkedList.removeNode(name);
        sizeTotal = sizeTotal - remsize;
        break;
      case 3: //If user wishes to fragment.
        LinkedList.fragments();
        break;
      case 4: //If user wishes to print the Linked List.
        LinkedList.print();
        break;
      case 5: //If user wishes to exit the program.
        return(0);
        break;
      default: //If the input is invalid.
        cout << "Invalid choice. Please try again." << endl;
      }
    }
  return 0;
}
