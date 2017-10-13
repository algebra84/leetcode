#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool isValidSudoku(vector<vector<char> >& board){
  char a[]={'1','2','3','4','5','6','7','8','9'};
  set<char> t(a,a+9);
  vector<set<char> > rows(9,t);
  vector<set<char> > cols(9,t);
  vector<set<char> > mid(9,t);
  for(int i = 0; i != board.size();i++)
    for(int j = 0; j != board.size(); j++){
      if(board[i][j] == '.')
        continue;
      if(rows[i].count(board[i][j]) == 0)
        return false;
      rows[i].erase(board[i][j]);
      if(cols[j].count(board[i][j]) == 0)
        return false;
      cols[j].erase(board[i][j]);
      if(i >= 3 && i < 6 && j >= 3 && j < 6){
        if(mid[3*(i-3)+j-3].count(board[i][j]) == 0)
          return false;
        mid[3*(i-3)+j-3].erase(board[i][j]);
      }
    }
  return true;
}

int main()
{
  string a[9]={".87654321",
               "2........",
               "3........",
               "4........",
               "5........",
               "6........",
               "7........",
               "8........",
               "9........"};
  vector<vector<char> > board;
  //  cout<<a[0]<<endl;
  for(int i = 0; i != 9; i++)
    board.push_back(vector<char>(a[i].begin(),a[i].end()));
  cout<<isValidSudoku(board)<<endl;
  return 1;
}
