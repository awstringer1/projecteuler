/*
 * Project Euler question 8
 * Largest product in a series
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

static int num_digits = 13;

// Calculate the product of integers in a string
long  int calculate_product(std::string x,bool debug=false) {
  
  long int the_product = 1;
  long int current_character;
  
  if (debug) {
    std::cout << "Calculating product of " << x << "\n";
  }
  
  int i;
  for (i=0;i<x.size();i++) {
    current_character = std::stol(x.substr(i,1),nullptr);
    if (debug) {
      std::cout << "Current character: " << x[i] << "\n";
      std::cout << "Current character as long int: " << current_character << "\n";
      std::cout << "Current value of the product: " << the_product << "\n";
    }
    the_product *= current_character;
    if (debug) {
      std::cout << "Value after multiplying by " << x[i] << ": " << the_product << "\n";
    }
  }
  return the_product;
}

int main() {
  
  std::string input_filepath = "/Users/alexstringer/phd/projects/learn-cpp/project-euler-not-xcode/q8inputfile.txt";
  std::ifstream input_file;
  input_file.open(input_filepath);
  // Check that the file was opened
  if (input_file) {
    std::cout << "File opened successfully. Reading...\n";
  }
  else {
    std::cout << "File not opened successfully\n";
    exit(1);
  }
  
  // Read the file character-by-character
  std::string sequence;
  char placeholder;
  int n = 0;
  while (input_file >> placeholder) {
    // std::cout << "Read character: " << placeholder << "\n";
    n++;
    sequence.push_back(placeholder);
  }
  
  // int i;
  // for (i=0;i<sequence.size();i++) {
  //   std::cout << sequence[i];
  // }
  
  std::cout << "Read " << n << " characters\n";
  std::cout << "Calculating products...\n";
  
  // Calculate the greatest product in the string
  // Doing this brute-force should be linear in the string size,
  // because we're considering only products of adjacent digits
  // Loop through each adjacent 13-character substring, calculate
  // the product, and compare to the maximum product found so far
  long int max_product = 0;
  long int current_product;
  int i;
  std::string current_substring;
  for (i=0;i<sequence.size() - num_digits;i++) {
    current_substring = sequence.substr(i,num_digits);
    // Calculate the product here
    current_product = calculate_product(current_substring);
    if (current_product > max_product) {
      // std::cout << "Current string with max product: " << current_substring << "\n";
      // std::cout << "Current max product: " << current_product << "\n";
      // calculate_product(current_substring,true);
      max_product = current_product;
    }
  }
  
  std::cout << "Maximum product of consecutive digits: " << max_product << "\n";
  
  
}
