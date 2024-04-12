/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */

function getLength(head) {
  return head ? 1 + getLength(head.next) : 0;
}

var getIntersectionNode = function(headA, headB) {
  const lengthA = getLength(headA);
  const lengthB = getLength(headB);

  if (lengthA > lengthB) {
    for (let i = 0; i < lengthA - lengthB; i++) {
      headA = headA.next;
    }
  }
  else {
    for (let i = 0; i < lengthB - lengthA; i++) {
      headB = headB.next;
    }
  }

  while(headA !== headB) {
    headA = headA.next;
    headB = headB.next;
  }
  return headA;
};