/* 212. Word Search II */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Trie{
public:
  Trie* children[26];
  bool leaf;
  int index;
  Trie(){
    leaf = false;
    index = -1;
    fill_n(children,26,nullptr);
  }
  ~Trie(){
    for(auto i = 0; i != 26; i++) delete children[i];
  }

};

void insertWords(Trie* root, vector<string>& words, int index){
  for(int i = 0; i != words[index].size();i++){
    if(root->children[words[index][i]-'a'] == nullptr)
      root->children[words[index][i]-'a'] = new Trie();
    root=root->children[words[index][i]-'a'];
  }
  root->leaf = true;
  root->index = index;
}
Trie* buildTrie(vector<string>& words){
  Trie* root = new Trie();
  for(int i = 0; i != words.size(); i++)
    insertWords(root,words,i);
  return root;
}

void checkWords(int i, int j, vector<vector<char> >& board,
                vector<string>& words,
                Trie* root, vector<string>& res){
  char c = board[i][j];
  int index = c-'a';
  int row = board.size();
  int col = board[0].size();
  if(c == 'X')
    return;
  if(root->children[index] == nullptr)
    return;

  if(root->children[index]->leaf){
    res.push_back(words[root->children[index]->index]);
    root->children[index]->leaf = false;
  }

  char tmp = board[i][j];
  root=root->children[index];
  board[i][j] = 'X';
  if(i > 0) checkWords(i-1,j,board,words,root,res);
  if(i+1 < row) checkWords(i+1,j,board,words,root,res);
  if(j > 0) checkWords(i,j-1,board,words,root,res);
  if(j+1 < col) checkWords(i,j+1,board,words,root,res);
  board[i][j] = tmp;
  return;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words){
  vector<string> res;
  if(words.size() == 0)
    return res;
  if(board.size() == 0)
    return res;
  if(board[0].size() == 0)
    return res;
  int row = board.size();
  int col = board[0].size();
  Trie* root = buildTrie(words);
  for(int i = 0; i != row; i++)
    for(int j = 0; j != col; j++)
      checkWords(i,j,board,words,root,res);
  return res;
}

int main()
{
  vector<string> words;
  words.push_back("vine");
  words.push_back("viner");
  words.push_back("wene");
  words.push_back("wots");
  char a[6][6]={
    {'s','e','e','n','e','w'},
    {'t','m','r','i','v','a'},
    {'o','b','s','i','b','d'},
    {'w','m','y','s','e','n'},
    {'l','t','s','n','s','a'},
    {'i','e','z','l','g','n'}};
  vector<char> c1(a[0],a[0]+6);
  vector<char> c2(a[1],a[1]+6);
  vector<char> c3(a[2],a[2]+6);
  vector<char> c4(a[3],a[3]+6);
  vector<char> c5(a[4],a[4]+6);
  vector<char> c6(a[5],a[5]+6);
  vector<vector<char> > b;
  b.push_back(c1);
  b.push_back(c2);
  b.push_back(c3);
  b.push_back(c4);
  b.push_back(c5);
  b.push_back(c6);
  vector<string> res = findWords(b,words);
  for(auto w:res)
    cout<<w<<endl;
  return 1;
}
