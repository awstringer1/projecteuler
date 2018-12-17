/*
 * Project Euler question 5: smallest positive number 
 * evenly divisible by all numbers from 1 - 20
 */

#include <iostream>

// Check if a number is divisible by all numbers from 1 - 20
bool isDivisible(long int x) {
  int i;
  for (i = 20; i >= 2; i--) {
    if (x % i != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  
  // 2520 is the smallest number that can be divided by 1 -- 10
  // Only check even numbers
  
  // long int x;
  // std::cout << "Enter number: ";
  // std::cin >> x;
  // 
  // std::cout << isDivisible(x) << "\n";
  
  long int x = 20;
  
  while(!isDivisible(x)) {
    std::cout << "Checked number " << x << "\n";
    x+=20;
  }
  
  std::cout << x << "\n";
}
