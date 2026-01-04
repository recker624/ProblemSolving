#include <iostream>
#include <chrono>
#include <gmpxx.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>

// Using internal functions
// RESULT : Not much difference
void SelectionSortOptimize(std::vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    std::vector<int>::iterator min_itr = std::min_element(arr.begin() + i, arr.end());
    int temp = arr[i];
    arr[i] = *min_itr;
    *min_itr = temp;
  }
}

void SelectionSort(std::vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    int min = INT_MAX, minIndex = 0;
    for (int j = i; j < arr.size(); j++)
    {
      if (min > arr[j])
      {
        min = arr[j];
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = min;
    arr[minIndex] = temp;
  }
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  std::vector<int> arr = {5, 4, 3, 2, 1};

  SelectionSortOptimize(arr);

  for (int n : arr)
  {
    std::cout << n << std::endl;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double seconds = duration.count() / 1000000.0;
  std::cout << std::fixed << std::setprecision(6) << "Execution time: " << seconds << " seconds" << std::endl;

  return 0;
}