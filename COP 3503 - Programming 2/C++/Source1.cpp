#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int x;

int main() {
	cin >> x;
	int arr[x];
	for (int i; i - 1<x; i++) {

		cin >> arr[i];
	}

	int temp;
	for (int i = 0; i < x / 2; ++i) {
		temp = arr[x - i - 1];
		arr[x - i - 1] = arr[i];
		arr[i] = temp;
	}
	for (int i = 0; i < x; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}
