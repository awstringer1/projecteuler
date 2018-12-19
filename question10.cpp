/*
 * Project Euler question 10: sum of all the primes below 2 million
 */

#include <iostream>
#include <math.h>
#include "primes.h"
#include <vector>

const long int N = 2000000;

int main() {
  // Hold all the primes below 2 million
  std::vector<long int> primes;
  
  // Find them with the sieve
  primes = sieve(N);
  
  // Sum them
  long int primesum = 0;
  int i;
  for (i=0;i < primes.size()-1;i++) {
    primesum += primes[i];
  }
  
  std::cout << "Sum of the primes below " << N << ": " << primesum << "\n";
}
