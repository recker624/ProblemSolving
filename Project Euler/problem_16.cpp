#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int count = 2;
  string s = "2";
  int carry = 0;
  int sum = 0;

  while (count <= 1000)
  {
    for (int i = 0; i < s.size(); i++)
    {
      int temp = s[i] - '0';
      temp *= 2;
      temp += carry;
      carry = 0;

      // if it has more than one digit
      if (temp / 10)
      {
        int rem = temp % 10;
        s[i] = '0' + rem;
        carry = temp / 10;
      }
      else
      {
        s[i] = '0' + temp;
      }
    }
    if (carry)
    {
      s += ('0' + carry);
      carry = 0;
    }
    count++;
  }

  // calculating the sum of digits
  for (char ch : s)
  {
    sum += (ch - '0');
  }

  cout << sum << endl;

  return 0;
}
