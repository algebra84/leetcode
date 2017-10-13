// 36. Valid Sudoku

#include<vector>
#include<iostream>
#include<set>
#include<string>
using namespace std;
#if 1
bool build_1(vector<vector<char> > &board,vector<set<char> > &rows,
             vector<set<char> > &cols,int row_index, int col_index){
  if(row_index == board.size())
    return true;
  if(board[row_index][col_index] != '.')
    if(col_index == board[row_index].size()-1)
      return build_1(board,rows,cols,row_index+1,0);
    else
      return build_1(board,rows,cols,row_index,col_index+1);
  vector<char> tmp;
  for (std::set<char>::iterator it=rows[row_index].begin(); it!=rows[row_index].end(); ++it)
    if(cols[col_index].count(*it))
      tmp.push_back(*it);
  for(int i = 0; i != tmp.size(); i++){
    rows[row_index].erase(tmp[i]);
    cols[col_index].erase(tmp[i]);
    if(col_index == board[row_index].size()-1){
      if(build_1(board,rows,cols,row_index+1,0))
        return true;
    }
    else{
      if (build_1(board,rows,cols,row_index,col_index+1))
        return true;
    }
    rows[row_index].insert(tmp[i]);
    cols[col_index].insert(tmp[i]);
  }
  return false;
}

bool isValidSudoku(vector<vector<char> >& board){
  if(board.size() == 0 || board[0].size() != board.size())
    return false;
  char a[] = {'1','2','3','4','5','6','7','8','9'};
  set<char> l(a,a+9);
  vector<set<char> > rows(9,l);
  vector<set<char> > cols(9,l);
  for(int i = 0; i != board.size(); i++)
    for(int j = 0; j != board.size();j++)
      if(board[i][j] == '.')
        continue;
      else{
        if(rows[i].count(board[i][j]) == 0)
          return false;
        rows[i].erase(board[i][j]);
        if(cols[j].count(board[i][j]) == 0)
          return false;
        cols[j].erase(board[i][j]);
      }
  return build_1(board,rows,cols,0,0);
}

#endif
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
