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
  TreeNode* duplicate(TreeNode* root){
    if(!root)
      return root;
    TreeNode* newroot = new TreeNode(root->val);
    TreeNode* left = duplicate(root->left);
    TreeNode* right = duplicate(root->right);
    newroot->left = left;
    newroot->right = right;
    return newroot;
  }
  vector<TreeNode*> buildTrees(int base, int n){
    vector<TreeNode* > resv;
    if(n == 1){
      TreeNode* res = new TreeNode(base);
      resv.push_back(res);
      return resv;
    }
    for(int i = 0; i != n; i++){
      if(i == 0){
        vector<TreeNode* > v = buildTrees(base+1, n-1);
        for(int j = 0; j != v.size(); j++){
          TreeNode* root = new TreeNode(base);
          root->right = duplicate(v[j]);
          resv.push_back(root);
        }
      }
      if(i == n-1){
        vector<TreeNode*> v = buildTrees(base, n-1);
        for(int j = 0; j != v.size(); j++){
          TreeNode* root = new TreeNode(base+n-1);
          root->left = duplicate(v[j]);
          resv.push_back(root);
        }
      }
      else{
        vector<TreeNode* > left = buildTrees(base, i);
        vector<TreeNode* > right = buildTrees(base+i+1, n-i-1);
        for(int j = 0; j != left.size(); j++)
          for(int k = 0; k != right.size(); k++){
            TreeNode* root = new TreeNode(base+i);
            root->left = duplicate(left[j]);
            root->right = duplicate(right[k]);
            resv.push_back(root);
          }
      }
    }
    return resv;
  }
  vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
      return vector<TreeNode*> ();
    return buildTrees(1, n);
  }
};

void inorder(TreeNode* root){
  if(!root)
    return;
  inorder(root->left);
  cout<<root->val<<",";
  inorder(root->right);
  return;
}
int main(){
  Solution p;
  vector<TreeNode* > res = p.generateTrees(5);
  for(int i = 0; i != res.size(); i++){
    inorder(res[i]);
    cout<<endl<<"---------------------"<<endl;
  }
  return 1;
}
