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
    TreeNode* root = new TreeNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TreeNode* p = root;
    for(int i = 0; i != word.size(); i++){
      if(!p->children[string[i]-'a'])
        p->chilren[string[i]-'a'] = new TreeNode();
      p=p->children[string[i]-'a'];
    }
    p->leaf = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {

  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {

  }
  ~Trie(){
    delete root;
  }
};
