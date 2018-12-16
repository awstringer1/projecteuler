/* Project Euler question 2
Find the sum of the even Fibonacci numbers whose values do
not exceed 4 million
*/

#include <iostream>

const int N = 4000000;

bool isEven(int x) {
	if (x % 2 == 0) {
		return true;
	}

	return false;
}

int main() {
	
	/* 
	The first two fibonacci numbers are 1 and 2
	Afterwards, Fib(n) = Fib(n-1) + Fib(n-2)
	*/
	int fibsum = 2;
	int fibnum[3]; // Array for storing the current and previous 2 fib numbers

	fibnum[0] = 1;
	fibnum[1] = 2;
	fibnum[2] = fibnum[0] + fibnum[1];

	// Until fibnum[3] > N, calculate the next fib number, check if even, and add to sum
	while (fibnum[2] <= N) {
		// Compute the next fibonacci number
		fibnum[2] = fibnum[0] + fibnum[1];
		// Check if evem
		if (isEven(fibnum[2])) {
			fibsum += fibnum[2];
		}
		// Increment
		fibnum[0] = fibnum[1];
		fibnum[1] = fibnum[2];
	}

	std::cout << fibsum << "\n";

}
