/* 211. Add and Search Word - Data structure design */

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class TreeNode{
public:
  TreeNode(){
    leaf = false;
    fill_n(children,26,nullptr);
  }
  TreeNode* children[26];
  bool leaf;
  ~TreeNode(){
    for(auto i = 0; i != 26; i++) delete children[i];
  }
};

class WordDictionary {
public:
  TreeNode* root;
  /** Initialize your data structure here. */
  WordDictionary() {
    root = new TreeNode();
  }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TreeNode *p = root;
    for(int i = 0; i != word.size(); i++){
      if(!(p->children[word[i]-'a']))
        p->children[word[i]-'a']=new TreeNode();
      p = p->children[word[i]-'a'];
    }
    p->leaf = true;
  }

  bool search_1(string& word, TreeNode* root, int index){
    if(root == NULL)
      return false;
    if(index == word.size())
      if(root->leaf == true)
        return true;
      else
        return false;
    if(word[index] == '.'){
      for(int i = 0; i != 26; i++){
        if(search_1(word,root->children[i],index+1))
          return true;
      }
      return false;
    }
    else{
      if(root->children[word[index]-'a'] != NULL)
        return search_1(word,root->children[word[index]-'a'],index+1);
      else
        return false;
    }

  }
  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return search_1(word, root, 0);
  }
  ~WordDictionary(){
    delete root;
  }
};

int main()
{
  WordDictionary wd;
  wd.addWord("dad");
  wd.addWord("bad");
  wd.addWord("mad");
  cout<<"pad: "<<wd.search("pad")<<endl;
  cout<<"bad: "<<wd.search("bad")<<endl;
  cout<<"..c: "<<wd.search("..c")<<endl;
  cout<<"b..: "<<wd.search("b..")<<endl;
  return 1;
}
