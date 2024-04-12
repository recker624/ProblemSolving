/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
let preorderTraversal = function(root) {
  if (root == null) return [];
  let arr = [];
  arr.concat([root.val, ...preorderTraversal(root.left), ...preorderTraversal(root.right)]);
  return arr;
};