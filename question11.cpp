/* 
 * Project Euler problem 11: products in a grid
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

int main() {
  // Open the input file
  std::string filepath = "/Users/alexstringer/phd/projects/learn-cpp/project-euler-not-xcode/q11inputfile.txt";
  std::ifstream input_file;
  input_file.open(filepath);
  // Check that the file was opened
  if (input_file) {
    std::cout << "File opened successfully. Reading...\n";
  }
  else {
    std::cout << "File not opened successfully\n";
    exit(1);
  }
  
  // Read it in to an integer array
  int thearray[20][20];
  std::string currentchar;
  int i = 0, j = 0;
  while (input_file >> currentchar) {
    // std::cout << "Current character: " << currentchar << "\n";
    thearray[i][j] = stoi(currentchar);
    std::cout << "Read in " << thearray[i][j] << " to thearray[" << i << "][" << j << "]\n";
    j++;
    if (j % 20 == 0) {
      i++;
      j = 0;
    }
  }
  
  // Now go over the array and find the maximum product
  long int maxprod = 0;
  long int curprod = 1;
  
  i=0; 
  j=0;
  while (i < 20) {
    // From the current spot (i,j), valid sequences have the following indices
    // (i,j), (i+1,j), (i+2,j), (i+3,j) (Down)
    // (i,j), (i,j+1), (i,j+2), (i,j+3) (Right)
    // (i,j), (i+1,j+1), (i+2,j+2), (i+3,j+3) (Diagonal, right/down)
    // (i,j), (i-1,j+1), (i-2,j+2), (i-3,j+3) (Diagonal, right/up)
    // 
    // So loop over them, checking whether each combination is entirely within range,
    // and then comparing the products to the max product
    // Don't need to consider backwards (up, left, left diag), products, since
    // these are captured on the way down
    // 
    // Down
    if (i+3 < 20) {
      curprod = thearray[i][j] * thearray[i+2][j] * thearray[i+2][j] * thearray[i+3][j];
      if (curprod > maxprod) {
        maxprod = curprod;
      }
    }
    // Right
    if (j+3 < 20) {
      curprod = thearray[i][j] * thearray[i][j+1] * thearray[i][j+2] * thearray[i][j+3];
      if (curprod > maxprod) {
        maxprod = curprod;
      }
    }
    // Diagonal down
    if (i+3 < 20 & j+3 < 20) {
      curprod = thearray[i][j] * thearray[i+1][j+1] * thearray[i+2][j+2] * thearray[i+3][j+3];
      if (curprod > maxprod) {
        maxprod = curprod;
      }
    }
    // Diagonal up
    if (i-3 >= 0 & j+3 < 20) {
      curprod = thearray[i][j] * thearray[i-1][j+1] * thearray[i-2][j+2] * thearray[i-3][j+3];
      if (curprod > maxprod) {
        maxprod = curprod;
      }
    }
    
    // Increment indices
    j++;
    if (j % 20 == 0) {
      i++;
      j = 0;
    }
  }
  
  std::cout << "Maximum product = " << maxprod << "\n";
  
}
