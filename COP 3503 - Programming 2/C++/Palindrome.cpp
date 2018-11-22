#include <iostream>

using namespace std;

int main(){

  int x;
  cin >> x;
  int reverse = 0;
  while (x !=0 ){

    int g = x % 10;
    reverse = reverse*10 +g;
    x = x /10;
  }

  if(x==reverse){

    cout << "Number is a palindrome.";
  }

  else {
      cout << "Number is not a palindrome.";

      }
  }
