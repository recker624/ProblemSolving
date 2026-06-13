#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>
#include <vector>

void bubble_sort_recursive(std::vector<int> &vec, int startIndex, int stopIndex) 
{
  if(startIndex - stopIndex == 0) return;

  for(int i=0; i < stopIndex; i++) {
    if (vec[i] > vec[i+1])
      vec[i] = vec[i] ^ vec[i+1];
      vec[i + 1] = vec[i] ^ vec[i+1];
      vec[i] = vec[i] ^ vec[i+1];
  }

  bubble_sort_recursive(vec, startIndex, stopIndex - 1);
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  std::vector<int> arr = {5, 4, 3, 2, 1};
  bubble_sort_recursive(arr, 0, arr.size() - 1);

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