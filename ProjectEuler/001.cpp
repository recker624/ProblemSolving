#include <iostream>
#include <chrono>

int main()
{
  auto start = std::chrono::high_resolution_clock::now();
  int sum = 0;
  for (int i = 1; i < 1000; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
      sum += i;
    }
  }

  std::cout << sum << std::endl;

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

  return 0;
}