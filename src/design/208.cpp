/*  
    Add to List
    208. Implement Trie (Prefix Tree) */
#include<string>
#include<iostream>
using namespace std;
class Trie {
public:
  class TreeNode{
  public:
    TreeNode* children[26];
    bool leaf;
    TreeNode(){
      leaf = false;
      fill_n(children,26,nullptr);
    }
    ~TreeNode(){
      for(int i = 0; i != 26; i++)
        delete children[i];
    }
  };
  TreeNode* root;
  /** Initialize your data structure here. */
  Trie() {
    root = new TreeNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TreeNode* p = root;
    for(int i = 0; i != word.size(); i++){
      if(!p->children[word[i]-'a'])
        p->children[word[i]-'a'] = new TreeNode();
      p=p->children[word[i]-'a'];
    }
    p->leaf = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TreeNode* p = root;
    for(int i = 0; i != word.size(); i++){
      if(p->children[word[i]-'a']==nullptr)
        return false;
      p = p->children[word[i]-'a'];
    }
    return p->leaf;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TreeNode* p = root;
    for(int i = 0; i != prefix.size(); i++){
      if(p->children[prefix[i]-'a'] == nullptr)
        return false;
      p = p->children[prefix[i]-'a'];
    }
    return true;
  }
  ~Trie(){
    delete root;
  }
};

int main()
{
  Trie obj;
  obj.insert("hello");
  cout<<obj.search("hell")<<endl<<obj.startsWith("hell")<<endl;
  return 1;
}
