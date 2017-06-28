/*79. Word Search */

#include<string>
#include<vector>
#include<iostream>
using namespace std;

bool exist_1(int row,int col,vector<vector<char> > &board,
             string &word,int index,
             vector<vector<int> > &visited)
{
  bool flag = false;
  if(index == word.size()-1){
    if(visited[row][col] == 0
       && board[row][col] == word[index])
      return true;
    return false;
  }
  if(visited[row][col] == 1)
    return false;
  if(board[row][col] != word[index])
    return false;
  visited[row][col] = 1;
  if(row > 0)
    flag = flag || exist_1(row-1,col,board,word,index+1,visited);
  if(row + 1< board.size())
    flag = flag || exist_1(row+1,col,board,word,index+1,visited);
  if(col > 0)
    flag = flag || exist_1(row,col-1,board,word,index+1,visited);
  if(col + 1< board[0].size())
    flag = flag || exist_1(row,col+1,board,word,index+1,visited);
  visited[row][col] = 0;
  return flag;
}
bool exist(vector<vector<char> >& board, string word)
{
  int row = board.size();
  if(row == 0)
    return false;
  int col = board[0].size();
  if(col == 0)
    return false;
  if(word.size() == 0)
    return false;
  int index = 0;
  vector<vector<int> > visited(row,vector<int> (col,0));
  bool flag = false;
  for(int i = 0; i != row; i++)
    for(int j = 0; j != col; j++){
      if(board[i][j] == word[0])
        flag = flag || exist_1(i,j,board,word,0,visited);
    }
  return flag;
 }

int main()
{
  int a[16]={'A','B','C','E',
               'S','F','C','S',
             'A','D','E','E'};
  vector<char> a1(a,a+4);
  vector<char> a2(a+4,a+8);
  vector<char> a3(a+8,a+12);
  vector<char> a4(a+12,a+16);
  vector<vector<char> > board;
  board.push_back(a1);
  board.push_back(a2);
  board.push_back(a3);
  board.push_back(a4);
  cout<<exist(board,"ABCB")<<endl;
  return 1;
}
