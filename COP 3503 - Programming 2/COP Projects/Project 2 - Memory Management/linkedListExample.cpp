#include "exampleHeader.h"


int main(int argc, char ** argv) {
  // argc is the number of arguments, argv is an array of the arguments
  // ./pa best pancakes in town!
  // argv[0] = ./pa
  // argv[1] = best
  // argv[2] = pancakes
  // ...
  // argv[4] = town!

	//prints arguments
	cout << "Printing out command line arguments:" << endl;
	for (int i = 0 ; i < argc ; ++i) {
		cout << "Argument " << i << ": " << argv[i] << endl;
	}

	if (argc > 2) { //need to check that there really are arguments before accessing argv[1]
		string argument = argv[1];
		if (argument.compare("best") == 0) {
			cout << "best argument passed" << endl;
		}
		else if (argument.compare("worst") == 0) {
      cout << "worst argument passed";
    }
    else {
      cout << "you didn't pass best or worst" << endl;
    }
	}
	LinkedList initial;
	cout << "linked list:\n";
	for(int i=0; i < 4; i++){
		for(int j=0; j < 8; j++){
		string x = "Free";
		initial.addNode(x);
	}
}
void addElement(string x, int page){
	int start=0;
		int temp = 0;
		for(int i=0; i<32; i++){
				if(head->data == "Free"){
					head=head->next;
					temp++;
					start=i;
				}
				else{
						head=head->next;
					temp=0;
				start=0;
				i=0;
				}
	}



				if(head->data == "Free"){
						temp++;
						if(temp == pages){
								for(int i=0; i<page; i++){
								head->data = x;
							 head = head->next;
						}
				}
		}


}
initial.printList();


	// 1
  //initial.addNode(2);
	// 1 -> 2
  //initial.addNode(3);
	// 1 -> 2 -> 3

//  initial.printList();
	//initial.deleteNode(2);
	// 1 -> 3
	//initial.deleteNode(3);
	// 1
	//initial.addNode(4);
	// 1 -> 4
  cout << "modified linked list:\n";
	initial.addNode("y");
  initial.printList();
  return 0;
}
