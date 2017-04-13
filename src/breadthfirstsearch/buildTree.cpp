/*105. Construct Binary Tree from Preorder and Inorder Traversal
  Given preorder and inorder traversal of a tree, construct the binary tree.

  Note:
  You may assume that duplicates do not exist in the tree.
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildTree_1(TreeNode* root, vector<int> preorder, vector<int> inorder){
  int val = root->val;
  int N = preorder.size();
  if(N == 1)
    return;
  vector<int>::iterator rootidx = find(inorder.begin(),inorder.end(), val);
  int leftlength = rootidx - inorder.begin();
  //no left tree
  int next = preorder[1];
  vector<int>::iterator nextidx = find(inorder.begin(), inorder.end(), next);
  if(!leftlength){
    TreeNode* tmp = new TreeNode(next);
    root->right = tmp;
    buildTree_1(tmp,vector<int>(preorder.begin()+1, preorder.end()), vector<int>(inorder.begin() + 1, inorder.end()));
    return;
  }
  //yes left tree
  TreeNode* left = new TreeNode(next);
  root->left = left;
  buildTree_1(left,vector<int>(preorder.begin()+1, preorder.begin()+1+leftlength), vector<int>(inorder.begin(),rootidx));
  //yes right tree
  if(leftlength + 1 != N){
    TreeNode* right = new TreeNode(preorder[leftlength+1]);
    root->right = right;
    buildTree_1(right,vector<int>(preorder.begin()+1+leftlength, preorder.end()), vector<int>(rootidx+1, inorder.end()));
  }

  return;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int N = preorder.size();
  if(N == 0)
    return NULL;
  TreeNode* root = new TreeNode(preorder[0]);
  buildTree_1(root, preorder, inorder);
  return root;
}

int main()
{
  TreeNode* root;
  int a[] = {1,2,3};
  int b[] = {2,1,3};
  vector<int> pre(a,a+3);
  vector<int> inorder(b, b+3);
  root = buildTree(pre,inorder);
  return root->val;
}
