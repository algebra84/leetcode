/*99. Recover Binary Search Tree
  Two elements of a binary search tree (BST) are swapped by mistake.

  Recover the tree without changing its structure.

  Note:
  A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
  Subscribe to see which companies asked this question.
*/

#include<queue>
#include<vector>
#include<iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void midOrder(TreeNode* node, vector<TreeNode*> &q){
  if(node == NULL)
    return;
  midOrder(node->left,q);
  q.push_back(node);
  midOrder(node->right,q);
}
void printTree(TreeNode* node){
  if(node == NULL)
    return;
  printTree(node->left);
  cout<<node->val<<endl;
  printTree(node->right);
}
void recoverTree(TreeNode* root){
  vector<TreeNode*> mqu;
  TreeNode* p1 = NULL;
  TreeNode* p2 = NULL;
  midOrder(root,mqu);
  bool flag = false;
  for(int i = 0; i != mqu.size() - 1; i++){
    if(mqu[i]->val > mqu[i+1]->val)
      if(!flag){
        p1 = mqu[i];
        flag = true;
        p2 = mqu[i+1];
      }
      else
        p2 = mqu[i+1];
  }
  int tmp = p2->val;
  p2->val = p1->val;
  p1->val = tmp;
  return;
}

int main()
{
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4 = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  p3->left = p2;
  p3->right = p4;
  p2->left = p1;
  p4->right = p5;
  p5->val = 2;
  p2->val = 5;
  cout<<"before:"<<endl;
  printTree(p3);
  cout<<"after"<<endl;
  recoverTree(p3);
  printTree(p3);
  return 1;
}
