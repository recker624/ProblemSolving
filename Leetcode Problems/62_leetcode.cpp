#include <iostream>
#include <ctime>
#include <vector>

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
    return uniquePaths_cached(m, n, memo);
  }

  int uniquePaths_cached(int m, int n, std::vector<std::vector<int>> &memo)
  {
    // base case
    if (m == 0 || n == 0)
      return 0;
    else if (m == 1 || n == 1)
      return 1;
    else if (m != memo.size() && n != memo[0].size() && memo[m - 1][n - 1] != 0)
      return memo[m - 1][n - 1];

    memo[m - 1][n - 1] = uniquePaths_cached(m - 1, n, memo) + uniquePaths_cached(m, n - 1, memo);

    if (m < memo[0].size() && n < memo.size())
      memo[n - 1][m - 1] = memo[m - 1][n - 1];

    return memo[m - 1][n - 1];
  }
};

int main()
{
  clock_t start = clock();

  Solution sol;
  std::cout << sol.uniquePaths(3, 7) << std::endl;

  clock_t end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken by program is : " << time_taken << " sec " << std::endl;

  return 0;
}