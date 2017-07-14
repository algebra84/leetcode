/* 173. Binary Search Tree Iterator */
#include<iostream>
#include<vector>
using namespace std;


// * Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
  TreeNode* p;
  vector<TreeNode*> vecp;
  BSTIterator(TreeNode *root) {
    p = root;
    while(p){
      vecp.push_back(p);
      p=p->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    if(vecp.empty())
      return false;
    return true;
  }

  /** @return the next smallest number */
  int next() {
    p = vecp.back();
    int res = p->val;
    vecp.pop_back();
    if(p->right != NULL){
      p=p->right;
      while(p){
        vecp.push_back(p);
        p=p->left;
      }
    }
    return res;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
