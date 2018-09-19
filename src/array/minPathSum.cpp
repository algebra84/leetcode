/* 64. Minimum Path Sum */
#include<vector>
#include<map>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
  static int minPathSum(vector<vector<int> >& grid) {
    int rows = grid.size();
    if(rows == 0)
      return -1;
    int columns = grid[0].size();
    vector<vector<int> > dp;
    for(int i = 0; i != rows; i++)
      dp.push_back(vector<int> (columns, INT_MAX));
    for(int i = 0; i != rows; i++)
      for(int j = 0; j != columns; j++){
        if(i == 0 && j == 0)
          dp[i][j] = grid[i][j];
        else if(i == 0)
          dp[i][j] = dp[i][j-1]+grid[i][j];
        else if(j == 0)
          dp[i][j] = dp[i-1][j]+grid[i][j];
        else
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
      }
    return dp[rows-1][columns-1];
  }
};

int main(){
  int a[3][3] = {{1,3,1}, {1,5,1},{4,2,1}};
  vector<vector<int> > grid;
  grid.push_back(vector<int> (a[0], a[0]+3));
  grid.push_back(vector<int> (a[1], a[1]+3));
  grid.push_back(vector<int> (a[2], a[2]+3));
  cout<<Solution::minPathSum(grid)<<endl;
}
