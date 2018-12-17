/*
 * Project Euler question 4: palindrome numbers
 * Find the largest palindrome made from the product of 3 digit numbers
 * 
 */

#include <iostream>
#include <string>

// Function to check if a given number is a palindrome
bool isPalindrome(long int n) {
  
  // Convert n to a string
  std::string nstr;
  nstr = std::to_string(n);
  
  // Length- if it's odd, remove the middle element
  // Save first half and last half into new strings
  std::string first_half, last_half;
  
  int nlength = nstr.length();
  if (nlength % 2 == 1) {
    first_half = nstr.substr(0,(nlength - 1)/2);
    last_half = nstr.substr((nlength+1)/2,(nlength - 1)/2);
  }
  else {
    first_half = nstr.substr(0,nlength/2);
    last_half = nstr.substr(nlength/2,nlength/2);
  }
  
  // Reverse the order of the second half
  std::reverse(last_half.begin(),last_half.end());
  
  // std::cout << "First half: " << first_half << "\n";
  // std::cout << "Second half: " << last_half << "\n";
  
  if (first_half.compare(last_half) == 0) {
    std::cout << nstr << " is a palindrome!\n";
    return true;
  }
  else {
    // std::cout << nstr << " is not a palindrome!\n";
    return false;
  }
}


int main() {
  
  long int n;
  std::cout << "Enter max number: ";
  std::cin >> n;
  std::cout << "\n";
  
  int i = n, j = n;
  long int thePalindrome = 0;
  
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) {
      if (isPalindrome(i*j)) {
        if (i*j > thePalindrome) {
          thePalindrome = i*j;
        }
      }
    }
  }
  
  std::cout << thePalindrome << "\n";

}
