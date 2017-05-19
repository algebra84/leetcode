/*240. Search a 2D Matrix II
  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

  Integers in each row are sorted in ascending from left to right.
  Integers in each column are sorted in ascending from top to bottom.
  For example,

  Consider the following matrix:

  [
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
  ]
  Given target = 5, return true.

  Given target = 20, return false.*/

#include<vector>
#include<iostream>
using namespace std;
bool searchMatrix(vector<vector<int> >& matrix, int target){
  int rows = matrix.size();
  if(rows == 0)
    return false;
  int cols = matrix[0].size();
  if(cols == 0)
    return false;
  int min_row=0,min_col=0;
  int max_row=rows,max_col=cols;
  for(int i = 0; i != rows; i++){
    if(matrix[i][cols-1] < target)
      min_row = i+1;
    if(matrix[i][0] > target){
      max_row = i;
      break;
    }
  }

  for(int j = 0; j != cols; j++){
    if(matrix[rows-1][j] < target)
      min_col = j+1;
    if(matrix[0][j] > target){
      max_col = j;
      break;
    }
  }
  if(min_row == -1 || min_col == -1)
    return false;
  for(int i = min_row; i != max_row; i++)
    for(int j = min_col; j != max_col; j++)
      if(matrix[i][j] == target)
        return true;
      else if(matrix[i][j] > target)
        break;
  return false;
}

int main()
{
  int a1[]={1,1};
  int a2[]={2,5,8,12,19};
  int a3[]={3,6,9,16,22};
  int a4[]={10,13,14,17,24};
  int a5[]={18,21,23,26,30};
  vector<vector<int> > matrix;
  vector<int> v1(a1,a1+2);
  vector<int> v2(a2,a2+5);
  vector<int> v3(a3,a3+5);
  vector<int> v4(a4,a4+5);
  vector<int> v5(a5,a5+5);
  vector<int> v6;

  matrix.push_back(v1);
  /*
  matrix.push_back(v2);
  matrix.push_back(v3);
  matrix.push_back(v4);
  matrix.push_back(v5);*/
 cout<<searchMatrix(matrix,1)<<endl;
}
