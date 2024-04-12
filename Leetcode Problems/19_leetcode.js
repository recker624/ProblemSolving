/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */


/*
edge cases:
removing the first element
*/

var removeNthFromEnd = function (head, n) {
  let p1, p2;
  p1 = p2 = head;

  let i = 0;
  while (i <= n) {
    p2 = p2.next;
    i++;
  }

  if (p2 == null) {
    head = head.next;
    return head;
  }

  //iterate until p2 reaches end of list
  while (p2.next != null) {
    p1 = p1.next;
    p2 = p2.next;
  }
  
  //remove the nth element from the end
  p1.next = p1.next.next;

  return head;
};