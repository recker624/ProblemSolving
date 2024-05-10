#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int power)
  {
    int score = 0;
    int start = 0;
    int end = tokens.size() - 1;

    sort(tokens.begin(), tokens.end());

    while (start <= end)
    {
      // FACE UP
      if (power - tokens[start] >= 0)
      {
        power -= tokens[start];
        start++;
        score++;
      }
      else if (start == end || score == 0)
      {
        break;
      }
      // FACE DOWN
      else if (power + tokens[end] >= tokens[start])
      {
        power += tokens[end];
        end--;
        score--;
      }
    }
    return score;
  }
};

int main()
{
  vector<int> tokens = {58, 191};
  int power = 50;
  Solution s;
  cout << s.bagOfTokensScore(tokens, power) << endl;
  return 0;
}