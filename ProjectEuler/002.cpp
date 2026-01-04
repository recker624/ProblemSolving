#include <iostream>
#include <chrono>
#include <iomanip>

// There's and alternative more efficient approach to this.
/*
 follow the formula for even fibonacchi numbers => F(n) = 4 * F(n-1) + F(n-2)
 This way we can avoid calculating numbers that're not even. Accelerating computations.
*/

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  // Find the sum of even valued Fibonacchi numbers <= 4,000,000
  int a, b, c, sum = 2;
  a = 1;
  b = 2;
  for (int c = 0; c <= 4000000;)
  {
    c = a + b;
    a = b;
    b = c;
    if (c % 2 == 0)
      sum += c;
  }

  std::cout << "Answer : " << sum << std::endl;

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double seconds = duration.count() / 1000000.0;
  std::cout << std::fixed << std::setprecision(6) << "Execution time: " << seconds << " seconds" << std::endl;

  return 0;
}
