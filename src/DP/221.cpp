/* 221. Maximal Square */

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int build_1(vector<vector<char> > &matrix, int i, int j,
            vector<vector<int> > &mmap){
  if(i == matrix.size()-1 || j == matrix[0].size()-1)
    return matrix[i][j] == '1';

  if(mmap[i][j] != -1)
    return mmap[i][j];
  int res = 0;
  if(matrix[i][j] == '0')
    return 0;
  else{
    int res1 = build_1(matrix,i+1,j,mmap);
    int res2 = build_1(matrix,i,j+1,mmap);
    if(res1 != res2)
      mmap[i][j] = min(res1,res2)+1;
    else
      mmap[i][j] = res1+(matrix[i+res1][j+res1] == '1');
  }
  return mmap[i][j];
}
int maximalSquare(vector<vector<char> >& matrix){
  int row = matrix.size();
  if(row == 0)
    return 0;
  int col = matrix[0].size();
  if(col == 0)
    return 0;
  int res = 0;
  vector<vector<int> > mmap(row,vector<int> (col, -1));
  for(int i = 0; i != row; i++)
    for(int j = 0; j != col; j++){
      res = max(res,build_1(matrix,i,j,mmap));
    }
  return res*res;
}

int main()
{
  char a[5][5]={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  vector<vector<char> > matrix;
  for(int i = 0; i != 4; i++)
    matrix.push_back(vector<char>(a[i],a[i]+5));
  cout<<maximalSquare(matrix)<<endl;
  return 1;
}
