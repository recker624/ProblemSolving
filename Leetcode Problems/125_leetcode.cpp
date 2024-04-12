#include <iostream>
#include <ctime>
#include <string>
#include <locale>

class Solution
{
public:
  bool isPalindrome(std::string s)
  {
    std::locale loc;
    for (int i = 0, j = s.size() - 1; i < j;)
    {
      if (isalnum(s[i], loc) == false)
      {
        i++;
        continue;
      }
      if (isalnum(s[j], loc) == false)
      {
        j--;
        continue;
      }
      if (tolower(s[i], loc) != tolower(s[j], loc))
      {
        return false;
      }
      else
      {
        i++;
        j--;
      }
    }
    return true;
  }
};

int main()
{
  clock_t start = clock();

  Solution sol;
  std::string s = "A man, a plan, a canal: Panama";

  std::cout << (sol.isPalindrome(s) ? "True" : "False") << std::endl;

  clock_t end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken by program is : " << time_taken << " sec " << std::endl;

  return 0;
}