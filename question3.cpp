/* Project Euler question 3
Find the largest prime factor of a number
*/

#include <iostream>

const long int N = 600851475143;

// Check if a number is even
bool isEven(long int x) {
	if (x % 2 == 0) {
		return true;
	}

	return false;
}

// Naive implementation of prime checking
bool isPrime(long int x) {
	if (x == 1 | x == 2) {
		return true;
	}
	else if (isEven(x)) {
		return false;
	}

	// Assume x is odd
	long int highest_to_check;
	highest_to_check = (x + 1) / 2;

	int i;

	for (i=3;i<=highest_to_check;i+=2) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;

}

// Get the largest factor of a number
long int getLargestFactor(long int x) {
	// if (isPrime(x)) {
	// 	return x;
	// }
	if (isEven(x)) {
		return getLargestFactor(x / 2);
	}
	// Now assume x is odd
	// Loop through all odd numbers up to (x-1)/2
	// If any divide x, call function on x / that number
	int i;
	long int M;
	M = (x+1)/2;
	
	for (i=3; i <= M; i+=2) {
	  if (x % i == 0) {
	    return getLargestFactor(x / i);
	  }
	}
	
	// If we reach this point, x is prime
	return x;
}

int main() {

  long int x;
  std::cout << "Enter number: ";
  std::cin >> x;
  std::cout << "Largest prime factor of " << x << " is " << getLargestFactor(x) << "\n";
  
}
