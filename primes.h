/*
 * Header file containing prime functions
 * 
 * - Sieve of Erastones or whoever
 * - isPrime, naive prime check
 */

#include <iostream>
#include <math.h>
#include <vector>

bool isEven(long int x) {
  if (x % 2 == 0) {
    return true;
  }
  
  return false;
}

bool isPrime(long int x) {
  if (x == 1 | x == 2) {
    return true;
  }
  else if (isEven(x)) {
    return false;
  }
  
  // Assume x is odd
  long int highest_to_check;
  double xsqrt;
  xsqrt = sqrt(x);
  highest_to_check = int(xsqrt) + 1;
  
  int i;
  
  for (i=3;i<=highest_to_check;i+=2) {
    if (x % i == 0) {
      return false;
    }
  }
  
  return true;
  
}


// The Sieve of Eratosthenes
// Return all the primes up to a given point
// Returns a pointer to an array holding these values
std::vector<long int> sieve(long int n) {
  // static long int nums[10];
  std::vector<bool> A;
  int i;
  
  for (i=0;i<n;i++) {
    A.push_back(true); // Initialize an array of all trues
  }
  
  // Sieve of Eratosthenes
  double sqrtn = sqrt(n);
  int sqrtn_int = (int) sqrtn + 1;
  
  int j;
  // std::cout << "Starting first loop\n";
  for (i = 2; i <= sqrtn_int; i++) {
    // std::cout << "i = " << i << "\n";
    if (A[i-2]) {
      // std::cout << "A[" << i - 2 << "] is true.\n";
      for (j = pow(i,2); j <= n; j += i) {
        // std::cout << "j = " << j << "\n";
        // std::cout << "Setting A[" << j-2 << "] to false\n";
        A[j-2] = false;
      }
    }
  }
  
  // std::cout << "Starting second loop\n";
  std::vector<long int> out;
  for (i=0;i<n;i++) {
    // std::cout << "i = " << i << "\n";
    if (A[i]) {
      // std::cout << "A[" << i << "] is true.\n";
      // std::cout << "Adding " << i+2 << " to out\n";
      out.push_back(i+2);
    }
  }
  
  return out;
}
