/* 59. Spiral Matrix II */
#include <iomanip>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  void buildSquare(vector<vector<int> > &matrix, int row, int num){
    int n = matrix.size();
    for(int i = row; i != n-row; i++)
      matrix[row][i] = num++;
    num--;
    for(int i = row; i != n-row; i++)
      matrix[i][n-row-1] = num++;
    num--;
    for(int i = n-row-1; i != row-1; i--)
      matrix[n-row-1][i] = num++;
    num--;
    for(int i = n-row-1; i != row; i--)
      matrix[i][row] = num++;
    if(row == (matrix.size()-1)/2)
      return;
    buildSquare(matrix, row+1, num);
    return;
  }
  vector<vector<int> > generateMatrix(int n) {
    if(n == 0)
      return vector<vector<int> > ();
    vector<int> row(n, 0);
    vector<vector<int> > matrix(n, row);
    buildSquare(matrix, 0, 1);
    return matrix;
  }
};

int main(){
  Solution s;
  vector<vector<int> > matrix = s.generateMatrix(6);
  for(int i = 0; i != matrix.size(); i++){
    for(int j = 0; j != matrix[i].size(); j++)
      cout<<setw(3)<<matrix[i][j]<<"   ";
    cout<<endl;
  }
  return 1;
}
