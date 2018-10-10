/* 103. Binary Tree Zigzag Level Order Traversal */
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
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
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if(!root) return result;
    deque<TreeNode*> tree;
    tree.push_back(root);
    int flag=0;
    while(!tree.empty()){
      int count=tree.size();
      vector<int> level;
      while(count-- > 0){
        TreeNode* cur=tree.front();
        tree.pop_front();
        level.push_back(cur->val);
        if(cur->left) tree.push_back(cur->left);
        if(cur->right) tree.push_back(cur->right);
      }
      if(flag & 1) reverse(level.begin(), level.end());
      result.push_back(level);
      flag++;

    }
    return result;
  }

};
