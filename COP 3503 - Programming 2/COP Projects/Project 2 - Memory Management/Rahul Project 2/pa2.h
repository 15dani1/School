//Rahul Dani (9013-1693)- COP 3503 Project 2 - OS Memory Allocation
//This Project will emulate the OS's responsibility of allocating
//-memory to certain programs using best and worst fit algorithms.
//This is the pa2 header file.
//Citation: Some of the LinkedList creation ideas came from the Canvas powerpoint
//          named "Marc's Stuff".

#ifndef pa2_h
#define pa2_h
#include <string>
#include <climits>

using namespace std;

//Node creation class.
class Nodecreation {
public:
        string data;
        Nodecreation *next;
        Nodecreation(string name){
          data = name;
          next =NULL;
        }
};

//Linked List creation class.
class LinkedList {
        Nodecreation* head = NULL;
        Nodecreation* curr = NULL;
        Nodecreation* temp = NULL;

  public:
    //Constructors for initializing the functions.
    int removeNode(string name); //Method for removing program.
    int validInput(int input); //Method for checking valid input.
    void print(); //Method for printing Linked list.
    void bestFit(string name, int size); //Adding the program using best fit algorithm.
    void worstFit(string name, int size); //Adding the program using worst fit algorithm.
    void fragments(); //Method for checking number of fragments.
    int fitType(string type); //Method for picking the type of algorithm.

LinkedList( ){
    head=NULL;
    curr=NULL;
    temp=NULL;
  }

void makeNode(string name){ //Method for adding new nodes.
  if (head == NULL) {
    head = new Nodecreation(name);
  }
  curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new Nodecreation(name);
    }
};

int LinkedList::fitType(string type) { //Method for picking the type of algorithm.
   string fit = type; //Store selected algorithm.
   string best = "best";
   string worst = "worst";

   //Check for invalid user input.
   for (unsigned int i=0; i<fit.length(); i++){
   fit[i] = tolower(fit[i]);
   }
   //Picks Best Fit
   if (fit == best){
     cout << "Using best fit algorithm." << endl;
     return 1;
   }
   //Picks Worst Fit
   if (fit == worst){
     cout << "Using worst fit algorithm." << endl;
     return 0;
   }
   //Picks neither.
   else{
     cout << "Invalid input." << endl;
     return 2;
   }
}

int LinkedList::validInput(int input){ //Method for checking valid input.
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

int LinkedList::removeNode(string name) { //Method for removing program.
  int var3=1;
  int numPages=0;	//Number of pages.
  curr=head;
  for(int i=0;i<32;i++){
    if (curr->data == name){ // If the program already in place, set it to free.
      curr->data = "Free";
      numPages++;
      var3 = 0;
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

void LinkedList::fragments(){ //Method for checking number of fragments.
	curr = head;
	bool var = true;
	int fragment = 0; //Number of fragments
	do{ // Checks to see if free.
		if (curr == NULL) {
			cout << "No free fragments available\n";
			break;
		}
		else if (curr->data == "Free" && var){
			fragment++;
			var = false;
			curr = curr->next;
		}

		else if (curr->data == "Free" && var == false){ // Move on to the next node if still free.
			curr = curr->next;
		}

		else{ // If not free, then reset.
			var = true;
			curr = curr->next;
		}
	}while(curr != NULL);
	cout << "There are " << fragment << " fragment(s)" << endl;
}

void LinkedList::bestFit(string name, int size){ //Adding the program using best fit algorithm.
	curr = head;
	int pageNumber;
	int var = 1; //Test case for error.
	int var2 = 0;	//Test case for start of link index.
	int var4 = 0; //Test case for leftover index.
	int fragNum = 32; //Fragment number
	int var3 = 1; //Test case for free.
	int startFrag = 0; //Start location of the largest fragment.

	//Number of pages being used by the program.
	if (size%4 == 0){
		pageNumber = size/4;
	}
	else{
		pageNumber = size/4 + 1;
	}

	for(int i=0;i<32;i++){
		if (curr->data == name){ // If the program already exists, return error.
			cout << "Error, Program " << name << " already running." << endl;
			var3 = 0;
			break;
		}

		if(var3 ==1){ //Look for largest fragment.
			if (curr != NULL){
				if (curr->data == "Free" && var){ // Checks to see if free.
					var = false;
					curr = curr->next;
					var4++;
					var2=i+1;
				}

				else if (curr->data == "Free" && var == false){ // Move on to the next node if still free.
					curr = curr->next;
					var4++;
				}

				else{ //If not free, reset counter.
					var4=0;
					var = true;
					curr = curr->next;
				}
				if(var4 >= pageNumber){
					if (fragNum > var4){
					fragNum = var4;
					startFrag = var2;
					}
				}
			}
		}
	}

	curr = head;
	for(int i=1; i<=32; i++){
		if((i >= startFrag)&&(i< startFrag + pageNumber)){ //Look for free links and store input program.
			if (curr->data == "Free"){
					curr->data = name;
			}
		}
		curr = curr->next;
	}

	if (var3 !=0){ //algorithm is successful.
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
			if (curr != NULL){ // Loops until the end of the list
				if (curr->data == "Free" && var){ // Checks to see if free.
					var = false;
					curr = curr->next;
					var4++;
					var2=i+1;
				}

			else if (curr->data == "Free" && var == false){ // Move on to the next node if still free.
					curr = curr->next;
					var4++;
				}

			else{ // If not free, reset counter.
					var4 = 0;
					var = true;
					curr = curr->next;
				}
				if(var4 >= pageNumber){
					if (fragNum < var4){
					fragNum = var4;
					startFrag = var2;
					}
				}
			}
		}
	}

	curr = head;
	for(int j=1; j<=32;j++){
		if((j>=startFrag)&&(j<startFrag+pageNumber)){ //Look for free links and store input program.
			if (curr->data == "Free"){
					curr->data = name;
			}
		}
		curr = curr->next;
	}

	if (var3 !=0){ //The algorithm is successful.
		cout<< "Program " << name << " added successfully, " << pageNumber << " page(s) used." << endl;
	}
}

void LinkedList::print() { //Method for printing the Linked List.
  int printFormat =1; //Format Output.
  cout << endl;
  curr=head; 	//Start at head of link list.
  do {
    if(printFormat == 8){
      cout << curr->data << "\t" << endl;
      curr = curr->next;
      printFormat = 1;
    }
    else {
      cout << curr->data << "\t";
      curr = curr->next;
      printFormat++;
    }
  }

  while (curr != NULL); //Stop when there are no more links.
  cout << endl;
}

#endif
