#include <iostream>
#include <ctime>
#include <vector>

class Solution
{
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));

    return uniquePathsWithObstacles_cached(m, n, memo, obstacleGrid);
  }

  int uniquePathsWithObstacles_cached(int m, int n, std::vector<std::vector<int>> &memo, std::vector<std::vector<int>> &obstacleGrid)
  {
    // base case
    if (m == 0 || n == 0)
      return 0;
    else if (obstacleGrid[m - 1][n - 1] == 1)
      return 0;
    else if (m == 1 && n == 1)
      return 1;
    else if (memo[m - 1][n - 1] != -1)
      return memo[m - 1][n - 1];

    memo[m - 1][n - 1] = uniquePathsWithObstacles_cached(m - 1, n, memo, obstacleGrid) + uniquePathsWithObstacles_cached(m, n - 1, memo, obstacleGrid);

    return memo[m - 1][n - 1];
  }
};

int main()
{
  clock_t start = clock();

  std::vector<std::vector<int>> obstacleGrid = {{0, 1}, {0, 0}};

  Solution sol;
  std::cout << sol.uniquePathsWithObstacles(obstacleGrid) << std::endl;

  clock_t end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken by program is : " << time_taken << " sec " << std::endl;

  return 0;
}