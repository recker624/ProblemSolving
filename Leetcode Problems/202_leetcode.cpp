#include <iostream>
#include <unordered_map>
using namespace std;

/*
How to solve :
 1) We first use the modulus operator and the division operator to seperate the digits of the number and calculate the sum of squares.
 2) The calculated sum is then compared to the values stored in a map/dictionary. If they are found it means a loop is detected, else we store it in the map
 and the repeat the cycle until either 1 is found or a loop is detected.
*/

class Solution
{
public:
  bool isHappy(int n)
  {
    unordered_map<int, int> storage;
    int num = n;
    int sum = 0;
    storage[num] = 1;

    while (true)
    {
      while (num != 0)
      {
        int rem = num % 10;
        sum += (rem * rem);
        num /= 10;
      }
      if ((sum == 1))
      {
        return true;
      }
      else if (storage.find(sum) != storage.end())
      {
        return false;
      }

      storage[sum] = 1;
      num = sum;
      sum = 0;
      cout << num << '\n';
    }
  }
};

int main()
{
  Solution s;
  if (s.isHappy(2))
  {
    cout << "Happy" << endl;
  }
  else
  {
    cout << "Sad" << endl;
  }
  return 0;
}
