#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
- Algorithm
- We iterate the entire list using two pointers p1 and p2 where p1 is one position less than p2. This setup will allow us to properly
  remove any node form the list, as we also need to keep track of previous node while traversing.
*/

class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
      if (curr->val == val)
      {
        if (prev == nullptr)
        {
          // this means that the head->val == val so we update the head to remove val
          head = head->next;
          curr = curr->next;
        }
        else
        {
          prev->next = curr->next;
          curr = curr->next;
        }
      }
      else
      {
        prev = curr;
        curr = curr->next;
      }
    }
    return head;
  }
};

int main()
{
  clock_t tStart = clock();

  vector<int> data = {7, 7, 7, 7};
  int val = 7;

  ListNode *head = new ListNode(data[0]);
  ListNode *current = head;

  // Iterate through the rest of the data to create the list
  for (size_t i = 1; i < data.size(); ++i)
  {
    current->next = new ListNode(data[i]);
    current = current->next;
  }

  Solution s;
  head = s.removeElements(head, val);

  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  cout << "Time Taken: " << (double)(clock() - tStart) / (CLOCKS_PER_SEC) << "\n";
  return 0;
}