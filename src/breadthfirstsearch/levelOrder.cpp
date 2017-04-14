/*102. Binary Tree Level Order Traversal
  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

  For example:
  Given binary tree [3,9,20,null,null,15,7],
  3
  / \
  9  20
  /  \
  15   7
  return its level order traversal as:
  [
  [3],
  [9,20],
  [15,7]
  ]
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<vector<int> > levelOrder(TreeNode* root) {
  vector<vector<int> > result;
  if(NULL == root)
    return result;
  result.push_back(vector<int>(1,root->val));
  queue<TreeNode*> tmp1;
  queue<TreeNode*> tmp2;
  vector<int> element;
  tmp1.push(root);
  while(tmp1.size() || tmp2.size()){
    if(tmp1.size()){
      TreeNode* p = tmp1.front();
      tmp1.pop();
      if(p->left){
        tmp2.push(p->left);
        element.push_back(p->left->val);
      }
      if(p->right){
        tmp2.push(p->right);
        element.push_back(p->right->val);
      }
    }
    else{
      swap(tmp1, tmp2);
      result.push_back(element);
      element.clear();
    }
  }
  return result;
}

int main()
{
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4  = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  TreeNode* p6 = new TreeNode(6);
  TreeNode* p7 = new TreeNode(7);
  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p2->right = p5;
  p3->left = p6;
  p6->right = p7;
  vector<vector<int> > res = levelOrder(p1);
  for(int i = 0; i != res.size(); i++){
    for(int j = 0; j != res[i].size(); j++){
      cout<<res[i][j]<<".";
    }
    cout<<endl;
  }
}
