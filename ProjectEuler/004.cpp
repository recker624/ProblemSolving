#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>

// Find the largest palindrome made from the product of two 3-digit numbers.

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  // Your code here.

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double seconds = duration.count() / 1000000.0;
  std::cout << std::fixed << std::setprecision(6) << "Execution time: " << seconds << " seconds" << std::endl;

  return 0;
}