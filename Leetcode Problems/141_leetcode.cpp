#include <iostream>
#include <ctime>
#include <string>
#include <locale>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// using floyd's cycle finding algorithm
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *p1 = head, *p2 = head; // p1 moves 1 step at a time, p2 moves 2 steps at a time
    if (head != NULL && head->next != NULL && head->next->next != NULL)
      p2 = head->next->next;
    else
      return false;

    while (true)
    {
      if (p1 == p2)
        return true;
      else
      {
        if (p2->next != NULL && p2->next->next != NULL)
        {
          p2 = p2->next->next;
          p1 = p1->next;
        }
        else
          return false;
      }
    }
    return false;
  }
};

int main()
{
  clock_t start = clock();

  Solution sol;
  // std::string s = "A man, a plan, a canal: Panama";
  ListNode list;

  std::cout << (sol.hasCycle(list) ? "True" : "False") << std::endl;

  clock_t end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken by program is : " << time_taken << " sec " << std::endl;

  return 0;
}