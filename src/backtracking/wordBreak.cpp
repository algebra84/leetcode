/* 140. Word Break II */
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class TreeNode{
public:
  TreeNode* children[256];
  bool is_word;
  int index;
  TreeNode(){
    is_word = false;
    index = -1;
    fill_n(children,256,nullptr);
  }
  ~TreeNode(){
    for(int i = 0; i != 256; i++)
      delete children[i];
  }
};
TreeNode* origin;
unordered_map<int,vector<string> > mmap;
void addWord(TreeNode* root, string word,int index){
  for(auto c:word){
    if(!root->children[c])
      root->children[c] = new TreeNode();
    root=root->children[c];
  }
  root->is_word = true;
  root->index = index;
  return;
}
void wordBreak_1(vector<string>& cand, string& s,
                 TreeNode* root, int index,
                 vector<string>& wordDict,
                 int start){
  string result;
  if(root == NULL)
    return ;
  if(index == s.size()){
    if(root->is_word){
      cand.push_back(wordDict[root->index]);
      for(int i = 0; i != cand.size();i++)
        result=result+cand[i]+" ";
      result.pop_back();
      mmap[start].push_back(result);
      cand.pop_back();
    }
    return;
  }
  if(root->is_word){
    cand.push_back(wordDict[root->index]);
    if(!mmap.count(index)){
      vector<string> cand_1;
      wordBreak_1(cand_1,s,origin,index,wordDict,index);
    }
    string tmp;
    for(int i = 0; i != cand.size();i++)
      tmp = tmp + cand[i] +" ";
    for(int i = 0; i != mmap[index].size();i++)
      mmap[start].push_back(tmp+mmap[index][i]);
    cand.pop_back();
  }
  wordBreak_1(cand,s,root->children[s[index]],index+1,wordDict,start);
  return;
}
vector<string> wordBreak(string s, vector<string>& wordDict) {

  TreeNode* root = new TreeNode();
  origin = root;
  for(int i = 0; i != wordDict.size();i++)
    addWord(root,wordDict[i],i);
  vector<string> cand;
  wordBreak_1(cand,s,root,0,wordDict,0);
  delete root;
  return mmap[0];
}

int main(){
  string s = "aaaaaaaaaaaaaaaaaab";
  vector<string> wd;
  #if 0
  wd.push_back("cat");
  wd.push_back("cats");
  wd.push_back("and");
  wd.push_back("sand");
  wd.push_back("dog");
  #endif
  #if 1
  wd.push_back("a");
  wd.push_back("aa");
  wd.push_back("ab");
  wd.push_back("aaa");
  wd.push_back("aaaa");
  wd.push_back("aaaaa");
  wd.push_back("aaaaaa");
  wd.push_back("aaaaaaa");
  wd.push_back("aaaaaaaa");
  wd.push_back("aaaaaaaaa");
  wd.push_back("aaaaaaaaaa");
  #endif
  vector<string> res = wordBreak(s,wd);
  for(int i = 0; i != res.size();i++)
    cout<<res[i]<<endl;
}
