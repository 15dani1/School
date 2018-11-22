#ifndef pa2_h
#define pa2_h
//The name of the file can be anything you want

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

//LinkedLists are basically containers that have nodePointers to nodeObjects
//Both pointer and object are defined inside the class
class LinkedList {
public:
    struct nodeObject {
        string data;
        nodeObject *next;
    };
    typedef struct nodeObject * nodePointer; //defines pointers to node objects
    nodePointer head;
    nodePointer curr;
    nodePointer temp;

public:
    LinkedList(); //constructor
  //  void makeNode(string valueToBeAdded); //adds node at the end of the linked list
    int removeNode(string name); //deletes specified node
    void print();
    int validInput(int input);
    void bestFit(string name, int size);
    void worstFit(string name, int size);
    void fragments();
    int fitType(string type);
};

LinkedList::LinkedList() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

int LinkedList::validInput(int input){
	int var =input; //Test case.
	while ((cin.fail()) || (cin.get()!='\n')) {
		cin.clear(); //Clear the Error Flags that appears.
		cin.ignore(INT_MAX, '\n'); // Skips to the next newline characters and ignore the integer maximum value of character on the same line.
		cout << "Invalid input." << endl;
		cout << "Enter a valid input:"<< endl;
		cin >> var;
	}
	return var;
}

int LinkedList::fitType(string type) {
   //Pick an algorithm to allocate the memory in the OS, worst fit or best fit.
   string fit = type; //Store selected algorithm.
   //Loop till correct value is chosen.
   string best = "best";
   string worst = "worst";

   //Check for invalid user input.
   for (unsigned int i=0; i<fit.length(); i++){
   fit[i] = tolower(fit[i]);
   }
   //Pick Best Fit
   if (fit == best){
     cout << "Using best fit algorithm." << endl;
     return 1;
   }
   //Pick Worst Fit
   if (fit == worst){
     cout << "Using worst fit algorithm." << endl;
     return 0;
   }
   //None
   else{
     cout << "Invalid input." << endl;
     return 2;
   }
 }

void LinkedList::bestFit(string name, int size){
	curr = head;
	int pageNumber;
	int var =1; //Test case for error.
	int var2 =0;	//Test case for start of link index.
	int var4=0; //Test case for leftover index.
	int fragNum=32; //Fragment number
	int var3 = 1; //Test case for free.
	int startFrag=0; //Start location of the largest fragment.

	//Number of pages being used by the program.
	if (size%4 == 0){
		pageNumber = size/4;
	}
	else{
		pageNumber = size/4 + 1;
	}
	//Loop till end.
	for(int i=0;i<32;i++){
		// If the program already exists, return error.
		if (curr->data == name){
			cout << "Error, Program " << name << " already running." << endl;
			var3 =0;
			break;
		}
		//Look for largest fragment.
		if(var3 ==1){
		// Loops until the end of the list
			if (curr != NULL){
				// Checks to see if free.
				if (curr->data == "Free" && var){
					var = false;
					curr = curr->next;
					var4++;
					var2=i+1;
				}
				// Move on to the next node if still free.
				else if (curr->data == "Free" && var == false){
					curr = curr->next;
					var4++;
				}
				// If not free, reset.
				else{
					var4=0;//Reset counter
					var = true;
					curr = curr->next;
				}
				if(var4>=pageNumber){
					if (count>var4){
					fragNum=var4;
					startFrag=var2;
					}
				}
			}
		}
	}
	//Pass through the links.
	curr = head;
	for(int i=1; i<=32;i++){
		//Look for free links and store input program.
		if((i>=startFrag)&&(i<startFrag+pageNumber)){
			if (curr->data == "Free"){
					curr->data = name;
			}
		}
		curr = curr->next;
	}
	// The algorithm is successful or not enough memory.
	if (var3 !=0){
		cout<< "Program " << name << " added successfully, " << pageNumber << " page(s) used." << endl;
	}
}

void LinkedList::worstFit(string name, int size){
	curr = head;
	int pageNumber;
	bool var = true; //Test case for free.
	int var2 = 0;	//Test case for start of link index.
	int var3=1; //Test case for error.
	int var4=0; //Test case for leftover index.
	int fragNum=0; //Fragment number
	int startFrag=0; //Start location of the largest fragment.

	//Number of pages being used by the program.
	if (size%4 == 0){
		pageNumber = size/4;
	}
	else{
		pageNumber = size/4 + 1;
	}
	//Loop till end.
	for(int i=0;i<32;i++){
		// If the program already exists, return error.
		if (curr->data == name){
			cout << "Error, Program " << name << " already running." << endl;
			var3 =0;
			break;
		}
		//Look for largest fragment.
		if(var3 ==1){
		// Loops until the end of the list
			if (curr != NULL){
				// Checks to see if free.
				if (curr->data == "Free" && var){
					var = false;
					curr = curr->next;
					var4++;
					var2=i+1;
				}
				// Move on to the next node if still free.
				else if (curr->data == "Free" && var == false){
					curr = curr->next;
					var4++;
				}
				// If not free, reset.
				else{
					test4=0;//Reset counter
					var = true;
					curr = curr->next;
				}
				if(test4>= pageNumber){
					if (count<var4){
					fragNum=var4;
					startFrag=var2;
					}
				}
			}
		}
	}

	//Pass through the links.
	curr = head;
	for(int i=1; i<=32;i++){
		//Look for free links and store input program.
		if((i>=startFrag)&&(i<startFrag+pageNumber)){
			if (curr->data == "Free"){
					curr->data = name;
			}
		}
		curr = curr->next;
	}
	 //The algorithm is successful.
	if (test3 !=0){
		cout<< "Program " << name << " added successfully, " << pageNumber << " page(s) used." << endl;
	}
}

void LinkedList::fragments(){
	curr = head;
	bool var = true;
	int numFrags = 0; //Number of fragments
	// Loops until the end of the list
	do{
		// Checks to see if free.
		if (curr == NULL) {
			cout << "No free fragments available\n";
			break;
		}
		else if (curr->data == "Free" && var){
			numFrags++;
			var = false;
			curr = curr->next;
		}
		// Move on to the next node if still free.
		else if (curr->data == "Free" && var == false){
			curr = curr->next;
		}
		// If not free, reset.
		else{
			var = true;
			curr = curr->next;
		}
	}while(curr != NULL);
	cout << "There are " << numFrags << " fragment(s)" << endl;
}

int LinkedList::removeNode(string name) {
  int var3=1;
  int numPages=0;	//Number of pages.
  curr=head;
  for(int i=0;i<32;i++){
    // If the program already exists, set it to free.
    if (curr->data == name){
      curr->data = "Free";
      numPages++;
      var3=0;
    }
    curr = curr->next;
  }
  if (var3==0){
    cout<<"Program " <<name<<" successfully killed, "<< numPages << " page(s) reclaimed." <<endl;
    return (numPages*4);
  }
  else{
    cout << "Unable to locate program with the provided name.\n";
    return 0;
  }
}

//actual code for methods are normally placed in the main cpp file, this is just an example that this works too
void LinkedList::print() {
  int printFormat =1; //Format Output.
  cout << endl;
  curr=head; 	//Start at head of link list.
  do {
    if(printFormat == 8){
      cout << curr->data << "\t" << endl;
      curr = curr->next;
      printFormat = 1; //reset
    }
    else {
      cout << curr->data << "\t";
      curr = curr->next;
      printFormat++;
    }
  }

  while (curr != NULL); //Stop when no more links.
  cout << endl;
}

void makeNode(string name){ //adds a node to the end of the linked list
  if (head == NULL) {
    head = new LinkedList(name);
  }
  curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new LinkedList(name);
    }
};

#endif
