/*101. Symmetric Tree
  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

  For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

  1
  / \
  2   2
  / \ / \
  3  4 4  3
  But the following [1,2,2,null,3,null,3] is not:
  1
  / \
  2   2
  \   \
  3    3*/

#include<iostream>
#include<deque>
using namespace std;
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

bool isSymmetric_1(deque<TreeNode*> ivec){
  deque<TreeNode* > visit;
  if(!(ivec.size()))
    return true;
  while(ivec.size()){
    if(ivec.front() == NULL && ivec.back() == NULL){
      ivec.pop_back();
      ivec.pop_front();
      continue;
    }
    if((ivec.front() == NULL && ivec.back() != NULL)
       || (ivec.front() != NULL && ivec.back() == NULL))
      return false;
    if(ivec.front()->val != ivec.back()->val)
      return false;
    visit.push_front(ivec.front()->right);
    visit.push_front(ivec.front()->left);
    visit.push_back(ivec.back()->left);
    visit.push_back(ivec.back()->right);
    ivec.pop_back();
    ivec.pop_front();
  }
  return isSymmetric_1(visit);
}
bool isSymmetric(TreeNode* root){
  if(root == NULL)
    return true;
  deque<TreeNode* > visit;
  visit.push_back(root->left);
  visit.push_back(root->right);
  return isSymmetric_1(visit);
}

int main()
{
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(2);
  TreeNode* p4 = new TreeNode(3);
  TreeNode* p5 = new TreeNode(3);
  p1->left=p2;
  p1->right=p3;
  p2->right=p4;
  p3->right=p5;
  cout<<isSymmetric(p1)<<endl;
}
