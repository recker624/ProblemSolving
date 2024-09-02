#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <time.h>
using namespace std;

/*
Algorithm:

- Check if the strings are equal length since that's the basic condition for strings to be isomorphic
- Use a map to set relationship between the characters of the two strings. Since a character in one string should always map to the same character in
 the other string for it to be isomorphic. This is the easiest way to do this.
*/

bool isIsomorphic(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }

  unordered_map<char, char> map1;
  unordered_map<char, char> map2;
  for (int i = 0; i < s.length(); i++)
  {
    if (map1.find(s[i]) != map1.end())
    {
      if (map1[s[i]] != t[i])
        return false;
    }
    else if (map2.find(t[i]) != map2.end())
    {
      if (map2[t[i]] != s[i])
        return false;
    }
    else
    {
      map1[s[i]] = t[i];
      map2[t[i]] = s[i];
    }
  }

  return true;
}

int main()
{
  clock_t tStart = clock();

  string s = "eggqqade";
  string t = "addbbcge";
  cout << isIsomorphic(s, t) << endl;

  cout << "Time Taken: " << (double)(clock() - tStart) / (CLOCKS_PER_SEC) << "\n";
  return 0;
}