#include <iostream>
#include <chrono>
#include <string>
#include <unordered_map>

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  int arr[] = {10, 5, 10, 15, 10, 5};
  std::unordered_map<int, int> count;

  for (int i : arr)
  {
    if (1)
    {
      1;
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

  return 0;
}