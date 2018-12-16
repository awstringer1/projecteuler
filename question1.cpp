/*
Project euler question 1, in C++
Find the sum of all the multiples of 3 or 5 below 1000
*/

#include <iostream>
#include <math.h>

const int N = 1000;


bool isMultiple(int x) {
	// Check if x is a multiple of 3 or 5
	if (x < 3 | x == 4) {
		return false;
	}
	if (x % 3 == 0) {
		return true;
	}
	if (x % 5 == 0) {
		return true;
	}

	return false;
}


int main() {
	
	int thesum = 0;
	int i;

	for (i=1;i<N;i++) {
		if (isMultiple(i)) {
			thesum += i;
		}
	}

	std::cout << thesum << "\n";
}