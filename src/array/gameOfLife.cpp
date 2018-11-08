/* 289. Game of Life */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int getValue (int value){
    int result;
    result = value % 2;
    return result != 0;
  }

  int getAround (int value){
    int result;
    result = value/2;
    int modres = value%2;
    if(modres < 0)
      result-=1;
    return -result;
  }
  void gameOfLife(vector<vector<int> >& board) {
    int rows = board.size();
    if (rows == 0)
      return;
    int cols = board[0].size();
    if(cols == 0)
      return ;

    for(int i = 0; i != rows; i++)
      for(int j = 0; j != cols; j++){
        int status = getValue(board[i][j]);
        int around = getAround(board[i][j]);
        for(int m = -1; m != 2; m++)
          for(int n = -1; n != 2; n++){
            if( m == 0 && n == 0)
              continue;
            if(i+m< 0 || i+m>=rows)
              continue;
            if(j+n<0 || j+n>=cols)
              continue;
            around += getValue(board[i+m][j+n]);
          }
        if(status == 0 && around == 3){
          board[i][j] = 1;
          for(int m = 0; m != 2; m++)
            for(int n = -1; n != 2; n++){
              if( m == 0 && n == 0)
                continue;
              if(i+m< 0 || i+m>=rows)
                continue;
              if(j+n<0 || j+n>=cols)
                continue;
              if(m == 0 && n < 0)
                continue;
              board[i+m][j+n]+=2;
            }
        }
        else if(status == 1 && (around < 2 || around > 3)){
          board[i][j] = 0;
          for(int m = 0; m != 2; m++)
            for(int n = -1; n != 2; n++){
              if( m == 0 && n == 0)
                continue;
              if(i+m< 0 || i+m>=rows)
                continue;
              if(j+n<0 || j+n>=cols)
                continue;
              if(m == 0 && n < 0)
                continue;
              board[i+m][j+n]-=2;
            }
        }
        else
          board[i][j] = status;

        cout<<"temp board: "<<endl;
        for(int p = 0; p != rows; p++){
          for(int q = 0; q != cols; q++)
            cout<<board[p][q]<<"   ";
          cout<<endl;
        }
      }
  }
};

int main()
{
  int a[4][3]={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
  vector<vector<int> > board;
  board.push_back(vector<int> (a[0],a[0]+3));
  board.push_back(vector<int> (a[1],a[1]+3));
  board.push_back(vector<int> (a[2],a[2]+3));
  board.push_back(vector<int> (a[3],a[3]+3));
  Solution sol;
  sol.gameOfLife(board);
  cout<<"new board: "<<endl;
  for(int i = 0; i != 4; i++){
    for(int j = 0; j != 3; j++){
      cout<<board[i][j]<<"  ";
    }
    cout<<endl;
  }
}
