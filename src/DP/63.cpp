/* 63. Unique Paths II */

#include<vector>
#include<iostream>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
  int m = obstacleGrid.size();
  if(m == 0)
    return 0;
  int n = obstacleGrid[0].size();
  if(n == 0)
    return 0;
  int a[m][n];
  for(int i = 0; i != m; i++)
    for(int j = 0; j != n; j++){
      if(i == 0){
        if(j == 0)
          a[i][j] = 1-obstacleGrid[m-i-1][n-j-1];
        else
          a[i][j] = obstacleGrid[m-i-1][n-j-1]?0:a[i][j-1];
      }
      else if(j == 0)
        a[i][j] =  obstacleGrid[m-i-1][n-j-1]?0:a[i-1][j];
      else{
        a[i][j] = obstacleGrid[m-i-1][n-j-1]?0:(a[i-1][j]+a[i][j-1]);
      }
    }
  return a[m-1][n-1];
}
