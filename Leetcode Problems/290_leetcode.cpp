#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

/*
1)Check the number of words in string. If it not equal to number of characters in the pattern, return false
2)Since each character in pattern corrospond to a word in the string we can use two unordered_map to check if they have a one-to-one relationship.
*/

class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<string, char> string_to_pattern;
    unordered_map<char, string> pattern_to_string;
    string temp = "";
    deque<string> strArr;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == ' ')
      {
        strArr.push_back(temp);
        temp = "";
        continue;
      }
      temp += s[i];
    }
    strArr.push_back(temp);
    if (strArr.size() != pattern.size())
    {
      return false;
    }

    // now we can check for one-to-one relationship
    for (int i = 0; i < strArr.size(); i++)
    {
      auto temp_1 = string_to_pattern.find(strArr[i]);
      auto temp_2 = pattern_to_string.find(pattern[i]);

      // generate the mapping from the string to pattern
      if (temp_1 == string_to_pattern.end())
      {
        string_to_pattern[strArr[i]] = pattern[i];
      }
      else if (pattern[i] != temp_1->second)
      {
        return false;
      }

      // now from pattern to stirng
      if (temp_2 == pattern_to_string.end())
      {
        pattern_to_string[pattern[i]] = strArr[i];
      }
      else if (strArr[i] != temp_2->second)
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution s;
  string pattern = "abba";
  string str = "dog cat cat dog";
  cout << s.wordPattern(pattern, str) << endl;
  return 0;
}