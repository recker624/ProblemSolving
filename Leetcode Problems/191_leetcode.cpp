#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution
{
public:
  int hammingWeight(int n)
  {
    int count = 0;
    while (n != 0)
    {
      count += (n & 1);
      n >>= 1;
    }
    return count;
  }
};

int main()
{
  clock_t tStart = clock();

  int n = 128;
  Solution s;
  cout << s.hammingWeight(n) << endl;

  cout << "Execution Time: " << (double)(clock() - tStart) / (CLOCKS_PER_SEC) << "\n";
  return 0;
}