#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

class Solution
{
public:
  bool canJumpIterative(std::vector<int> &nums)
  {
    std::stack<int> historyIndex; // vector is of the format [index, steps]
    std::vector<int> stepsArr(nums);
    bool canjump = false;
    int index = 0;           // the current location we are at in nums array
    int steps = stepsArr[0]; // how many max steps can we take while standing at 'index' position
    while (index < nums.size())
    {
      if (steps + index >= nums.size() - 1)
      {
        canjump = true;
        break;
      }
      else if (steps != 0 && (steps + index) < nums.size() - 1)
      {
        historyIndex.push(index);
        index += steps;
        steps = stepsArr[index];
      }
      else if (steps == 0 && !historyIndex.empty())
      {
        int temp = historyIndex.top();
        historyIndex.pop();
        index = temp;
        steps = stepsArr[index] = stepsArr[index] - 1;
      }
      else if (steps == 0 && historyIndex.empty())
      {
        break;
      }
    }

    return canjump;
  }

  bool canJump(std::vector<int> &nums)
  {
    bool canjump = false;
    int index = 0;
    int steps = nums[0];
    canjump = canJumpIterative(nums);
    // canJumpRecursive(nums, index, steps);
    return canjump;
  }

  bool canJumpRecursive(std::vector<int> &nums, int index, int steps)
  {
    bool canjump = false;
    if (index + steps < nums.size() - 1)
    {
      canjump = canJumpRecursive(nums, index + steps, nums[index + steps]);
      if (!canjump)
      {
      }
    }
    else if (index + steps >= nums.size() - 1)
    {
      canjump = true;
    }
    else if (steps == 0)
    {
      canjump = false;
    }
    return canjump;
  }
};

int main()
{
  clock_t start = clock();

  Solution sol;

  std::vector<int> nums = {2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
  std::cout << sol.canJump(nums) << std::endl;

  clock_t end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken by program is : " << time_taken << " sec " << std::endl;

  return 0;
}