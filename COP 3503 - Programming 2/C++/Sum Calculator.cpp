#include <iostream>

using namespace std;

int x;
int y;

/*
A program that finds the sum of every value between
two desired integers.
*/

int main() {
cout << "Type lower integer value: ";
cin >> x;
cout << "Type upper integer value: ";
cin >> y;
int i;
int r=x;

for (int i = r ; i < y;i++) {

  int z = i+1;
  r = r+z;

}

cout << "The sum of every value between " << x << " and " << y <<  " is: " << r;

}
