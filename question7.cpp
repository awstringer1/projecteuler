/*
 * Project Euler question 7: 10,001st prime number
 * 
 * The prime number theorem says that the nth prime number is close to nlog(n)
 * Also says that the number of primes less than n is approx n/log(n)
 * 
 */

#include <iostream>
#include <vector>
#include <math.h>

// The Sieve of Eratosthenes
// Return all the primes up to a given point
// Returns a pointer to an array holding these values
std::vector<long int> sieve(long int n) {
  // static long int nums[10];
  std::vector<long int> nums;
  std::vector<bool> A;
  int i;
  
  for (i=0;i<n;i++) {
    nums.push_back(i+1); // Add the nth number
    A.push_back(true); // Initialize an array of all trues
  }
  
  // Sieve of Eratosthenes
  double sqrtn = sqrt(n);
  int sqrtn_int = (int) sqrtn + 1;
  
  int j;
  for (i = 0; i < sqrtn_int - 2; i++) {
    if (A[i]) {
      for (j = pow(i+2,2); j <= n; j += i+2) {
        A[j] = false;
      }
    }
  }
  
  std::vector<long int> out;
  for (i=0;i<n;i++) {
    if (A[i]) {
      out.push_back(nums[i]);
    }
  }
  
  
  
  return out;
}

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  //std::cout << "\n";
  std::vector<long int> thesieve = sieve(n);
  std::cout << "Here the primes up to " << n << ": ";
  int i;
  for (i=0;i<n;i++) {
    if (abs(thesieve[i]) <= n) {
      std::cout << thesieve[i] << " ";
    }
  }
  std::cout << "\n";
}
