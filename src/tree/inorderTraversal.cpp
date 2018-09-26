#include<iostream>
#include<vector>
using namespace std;
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> res;
  void travel1(TreeNode* root){
    if(!root)
      return;
    travel1(root->left);
    res.push_back(root->val);
    travel1(root->right);
    return;
  }
  vector<int> inorderTraversal(TreeNode* root){
    res.clear();
    travel1(root);
    return res;
  }

};
