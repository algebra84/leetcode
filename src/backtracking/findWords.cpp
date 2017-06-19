/* 212. Word Search II */

#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<string> mset;
bool findWord_1(int row, int col, string word, int index,
                vector<vector<int> >&visited,
                vector<vector<char> >& board) {
  if(index == word.size())
    return true;
  int a[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
  for(int i = 0; i != 4; i++){
    if(row+a[i][0] >=0
          && row+a[i][0] < board.size()
          && col+a[i][1] >= 0
          && col+a[i][1] < board[0].size()
          && board[row+a[i][0]][col+a[i][1]] == word[index]
       && !visited[row+a[i][0]][col+a[i][1]]){
      bool flag;
      visited[row+a[i][0]][col+a[i][1]] = 1;
      flag = findWord_1(row+a[i][0],col+a[i][1],word,index+1,visited,board);
      if(flag)
        return true;
      visited[row+a[i][0]][col+a[i][1]] = 0;
    }
  }
  return false;
}
void findWord(vector<vector<char> >& board,
              string word, vector<string>& res){
  if(word.size() == 0)
    return;
  vector<vector<int> > visited(board.size(),vector<int>(board[0].size(),0));
  for(int i = 0; i != board.size(); i++)
    for(int j = 0; j != board[0].size(); j++){
      if(board[i][j] == word[0]){
        bool flag = false;
        visited[i][j] = 1;
        flag = findWord_1(i,j,word,1,visited,board);
        if(flag){
          res.push_back(word);
          return;
        }
        visited[i][j] = 0;
      }
    }
}
vector<string> findWords(vector<vector<char> >& board, vector<string>& words){
  vector<string> res;
for(auto s:words){
if(mset.count(s))
  continue;
mset.insert(s);
findWord(board, s,res);
}
return res;
}

int main()
{
  vector<string> words;
  words.push_back("eat");
  words.push_back("pea");
  words.push_back("eat");
  words.push_back("eat");
  char a[4][4]={
    {'o','a','a','n'},
    {'e','t','a','e'},
    {'i','h','k','r'},
    {'i','f','l','v'}};
  vector<char> c1(a[0],a[0]+4);
  vector<char> c2(a[1],a[1]+4);
  vector<char> c3(a[2],a[2]+4);
  vector<char> c4(a[3],a[3]+4);
  vector<vector<char> > b;
  b.push_back(c1);
  b.push_back(c2);
  b.push_back(c3);
  b.push_back(c4);

  vector<string> res = findWords(b,words);
  for(auto w:res)
    cout<<w<<endl;
  return 1;
}
