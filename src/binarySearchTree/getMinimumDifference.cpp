/*530. Minimum Absolute Difference in BST
  Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

  Example:

  Input:

  1
  \
  3
  /
  2

  Output:
  1

  Explanation:
  The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
  Note: There are at least two nodes in this BST.
*/
#include<queue>
using namespace std;
#define NULL 0
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getMinimumDifference(TreeNode* root) {
  int result = 100000;
  int up;
  priority_queue<int> q;
  queue<TreeNode*> qu;
  qu.push(root);
  while(qu.size()){
    TreeNode* p = qu.front();
    qu.pop();
    q.push(p->val);
    if(p->left)
      qu.push(p->left);
    if(p->right)
      qu.push(p->right);
  }
  up = q.top();
  q.pop();
  while(q.size()){
    if((up - q.top()) < result)
      result = up-q.top();
    up = q.top();
    q.pop();
  }
  return result;
}
