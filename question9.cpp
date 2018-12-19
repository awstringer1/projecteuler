/*
 * Project Euler question 9: Special Pythagorean Triplet
 * Find the product of abc for the pythagorean triplet a^2 + b^2 = c^2 having a + b + c = 1000
 * 
 * Occurs iff 2000(a+b) = 1000^2 + 2ab
 * And a,b have to be less than 1000
 */

#include <iostream>
#include <math.h>

bool checkCondition(int a, int b) {
  if (a == 0) {
    return false;
  }
  if (2000*(a+b) == pow(1000,2) + 2*a*b) {
    return true;
  }
  return false;
}

int main() {
  
  int a, b, c;
  
  // Now loop over 1...1000 and check the condition
  for (a=1;a<=1000;a++) {
    for (b=1;b<=1000;b++) {
      //std::cout << "i = " << i << ", j = " << j << "\n";
      if (checkCondition(a,b)) {
        c = 1000 - (a+b);
        std::cout << "a, b, c = " << a << " " << b << " " << c << "\n";
        std::cout << "Product = " << a*b*c << "\n";
        break;
      }
    }
  }
}
