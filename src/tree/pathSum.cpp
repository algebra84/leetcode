/* 113. Path Sum II */
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
  vector<vector<int> >ress;
  void pathSum1(TreeNode* root, int sum, vector<int> &res){
    if(root->left == NULL && root->right == NULL){
      if(sum == root->val){
        res.push_back(root->val);
        ress.push_back(res);
        res.pop_back();
      }
      return ;
    }
    res.push_back(root->val);
    if(root->left){
      pathSum1(root->left, sum-(root->val), res);
    }
    if(root->right){
      pathSum1(root->right, sum-(root->val), res);
    }
    res.pop_back();
    return ;
  }
  vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<int> res;
    if(!root)
      return ress;
    pathSum1(root, sum, res);
    return ress;
  }
};

int main(){
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4 = new TreeNode(4);
  TreeNode* p5 = new TreeNode(5);
  TreeNode* p6 = new TreeNode(6);
  Solution s;
  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p2->right = p5;
  p3->left = p6;
  vector<vector<int> > res = s.pathSum(p1, 7);
  for(int i = 0; i != res.size(); i++){
    for(int j = 0; j != res[i].size();j++)
      cout<<res[i][j]<<",";
    cout<<endl;
  }
}
