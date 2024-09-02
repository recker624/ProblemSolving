#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int target = 1000;

  std::string numbers1to19[] = {
      "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
      "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  // Array for tens (20, 30, ..., 90)
  std::string tens[] = {
      "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  int i = 0;
  int stringSize = 0;
  while (i <= target)
  {
    // count how many digits are in current number to decide what words to use
    int count = 0;
    int arr[4] = {-1, -1, -1, -1};
    int temp1 = i;

    while (temp1 != 0)
    {
      int rem = temp1 % 10;
      arr[count] = rem;
      count++;
      temp1 /= 10;
    }

    std::string numStr = "";
    if (count == 4 && arr[3] != 0)
    {
      numStr += numbers1to19[arr[3] - 1] + "thousand";
      count--;
    }

    if (count == 3 && arr[2] != 0)
    {
      numStr += numbers1to19[arr[2] - 1] + "hundred" + (arr[1] == 0 && arr[0] == 0 ? "" : "and");
      count--;
    }
    else if (count == 3) // if no hundreds, then skip
      count--;

    if (count == 2 && arr[1] != 0)
    {
      if (arr[1] == 1)
      {
        int temp = arr[1] * 10 + arr[0];
        numStr += numbers1to19[temp - 1];
        count -= 2;
      }
      else
      {
        numStr += tens[arr[1] - 2];
        count--;
      }
    }
    else if (count == 2) // if no tens, then skip
      count--;

    if (count == 1 && arr[0] != 0)
    {
      numStr += numbers1to19[arr[0] - 1];
    }

    stringSize += numStr.size();
    cout << numStr << endl;
    i++;
  }

  std::cout << stringSize << std::endl;

  return 0;
}