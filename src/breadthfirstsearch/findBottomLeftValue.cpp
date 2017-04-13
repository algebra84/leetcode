/*513. Find Bottom Left Tree Value
  Given a binary tree, find the leftmost value in the last row of the tree.

  Example 1:
  Input:

  2
  / \
  1   3

  Output:
  1
  Example 2: 
  Input:

  1
  / \
  2   3
  /   / \
  4   5   6
     /
    7

  Output:
  7
  Note: You may assume the tree (i.e., the given root node) is not NULL.*/

#include<iostream>
#include<queue>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
int findBottomLeftValue(TreeNode* root) {
  queue<TreeNode*> unvisited;
  int result = root->val;
  unvisited.push(root);
  while(unvisited.size()){
    TreeNode* tmp = unvisited.front();
    unvisited.pop();
    if(tmp->right)
      unvisited.push(tmp->right);
    if(tmp->left){
      result = tmp->left->val;
      unvisited.push(tmp->left);
    }
  }
  return result;
}


int main()
{
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4 = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  TreeNode* p6 = new TreeNode(6);
  TreeNode* p7 = new TreeNode(7);
  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p3->left = p5;
  p3->right = p6;
  p5->left = p7;
  cout<<findBottomLeftValue(p1)<<endl;
}

