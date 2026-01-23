#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>

// use this to compile and run ==> g++ 003.cpp -lgmp -lgmpxx -O2 -o a && ./a
/*
Refer to my logseq doc for more details.
*/

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  //  Find largest prime factor of number 600851475143
  mpz_class a, largest_factor;
  a = "600851475143";
  for (mpz_class i("2"); i <= a;)
  {
    if (a % i == 0)
    {
      a /= i;
      largest_factor = i;
    }
    else
    {
      i++;
    }
  }

  std::cout << "Answer : " << largest_factor << std::endl;

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double seconds = duration.count() / 1000000.0;
  std::cout << std::fixed << std::setprecision(6) << "Execution time: " << seconds << " seconds" << std::endl;

  return 0;
}
