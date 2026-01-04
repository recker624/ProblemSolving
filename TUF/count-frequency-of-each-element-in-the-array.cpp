#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>
#include <unordered_map>
#include <string>

void Frequency(int arr[], int n)
{
  std::unordered_map<int, int> map;
  for (int i = 0; i < n; i++)
  {
    map[arr[i]]++;
  }

  for (auto x : map)
  {
    std::cout << x.first << " : " << x.second << std::endl;
  }
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  // Input array
  int arr[] = {10, 5, 10, 15, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Call the function to count frequencies
  Frequency(arr, n);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double seconds = duration.count() / 1000000.0;
  std::cout << std::fixed << std::setprecision(6) << "Execution time: " << seconds << " seconds" << std::endl;

  return 0;
}