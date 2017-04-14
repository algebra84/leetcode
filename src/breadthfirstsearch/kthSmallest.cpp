/*230. Kth Smallest Element in a BST
  Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

  Note: 
  You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

  Follow up:
  What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


  Try to utilize the property of a BST.
  What if you could modify the BST node's structure?
  The optimal runtime complexity is O(height of BST).
*/

#include<vector>
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

class Solution {
public:
  void inorder_travel(TreeNode* root){
    if(root == NULL)
      return;
    inorder_travel(root->left);
    result.push_back(root->val);
    inorder_travel(root->right);
  }
  int kthSmallest(TreeNode* root, int k) {
    result.clear();
    inorder_travel(root);
    return result[k-1];
  }
private:
  vector<int> result;
};

int main()
{
  Solution s;
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4 = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  TreeNode* p6 = new TreeNode(6);
  TreeNode* p7 = new TreeNode(7);
  TreeNode* p8 = new TreeNode(8);
  p4->left=p2;
  p4->right = p7;
  p2->left = p1;
  p2->right = p3;
  p7->left = p6;
  p7->right = p8;
  p6->left = p5;
  for(int i = 0; i != 8; i++)
    cout<<s.kthSmallest(p4, i+1)<<endl;
  return 1;
}
