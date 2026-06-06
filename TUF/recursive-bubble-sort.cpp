#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>
#include <vector>

void bubble_sort(std::vector<int> &vec)
{
  // bubble sort algorithm implementation but recursively instead of using a FOR loop
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  std::vector<int> arr = {5, 4, 3, 2, 1};
  bubble_sort(arr);

  for (int i : arr)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double seconds = duration.count() / 1000000.0;
  std::cout << std::fixed << std::setprecision(6) << "Execution time: " << seconds << " seconds" << std::endl;

  return 0;
}