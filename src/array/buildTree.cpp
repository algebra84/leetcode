/* 106. Construct Binary Tree from Inorder and Postorder Traversal */

#include<vector>
#include<iostream>
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
  static TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0)
      return NULL;
    int size = inorder.size();
    int rootVal = postorder[size-1];
    TreeNode* root = new TreeNode(rootVal);
    vector<int> left_inorder;
    vector<int> right_inorder;
    vector<int> left_postorder;
    vector<int> right_postorder;
    int i;
    for(i = 0; i != size; i++){
      if(inorder[i] == rootVal)
        break;
    }
    for(int j = 0; j != i; j++){
      left_inorder.push_back(inorder[j]);
      left_postorder.push_back(postorder[j]);
    }

    for(int j = i; j != size-1; j++){
      right_inorder.push_back(inorder[j+1]);
      right_postorder.push_back(postorder[j]);
    }

    TreeNode* left = buildTree(left_inorder,left_postorder);
    TreeNode* right = buildTree(right_inorder, right_postorder);
    root->left = left;
    root->right = right;
    return root;
  }

};

int main(){
  int inorder[]={9,3,15,20,7};
  int postorder[]={9,15,7,20,3};
  vector<int> arg1(inorder, inorder+5);
  vector<int> arg2(postorder, postorder+5);
  TreeNode* p = Solution::buildTree(arg1, arg2);
  cout<<p->val<<endl;
  return 1;
}
