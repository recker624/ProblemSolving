#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>

#include <unordered_map>

void Frequency(int arr[], int n)
{
  std::unordered_map<int, int> map;
  int highest_freq = INT_MIN, maxEle;
  int lowest_freq = INT_MAX, minEle;
  for (int i = 0; i < n; i++)
  {
    map[arr[i]]++;
  }

  for (auto it : map)
  {
    int element = it.first;
    int count = it.second;

    // Update max frequency element
    if (count > highest_freq)
    {
      highest_freq = count;
      maxEle = element;
    }

    // Update min frequency element
    if (count < lowest_freq)
    {
      lowest_freq = count;
      minEle = element;
    }
  }

  std::cout << "Highest frequency : " << maxEle << std::endl;
  std::cout << "Lowest frequency : " << minEle << std::endl;
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