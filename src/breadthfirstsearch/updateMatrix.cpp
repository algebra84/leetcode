/*542. 01 Matrix
  Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

  The distance between two adjacent cells is 1.
  Example 1: 
  Input:

  0 0 0
  0 1 0
  0 0 0
  Output:
  0 0 0
  0 1 0
  0 0 0
  Example 2: 
  Input:

  0 0 0
  0 1 0
  1 1 1
  Output:
  0 0 0
  0 1 0
  1 2 1
  Note:
  1. The number of elements of the given matrix will not exceed 10,000.
  2. There are at least one 0 in the given matrix.
  3. The cells are adjacent in only four directions: up, down, left and right.*/

#include<vector>
#include<iostream>
#include<utility>
#include <queue>
#include<cmath>

using namespace std;
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix){
  int row = matrix.size();
  int col = matrix[0].size();
  int a[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
  vector<vector<int> > result(row, vector<int>(col, 0));
  for(int i = 0; i != row; i++)
    for(int j = 0; j != col; j++){
      vector<vector<bool> > visited(row,vector<bool>(col, false));
      queue<pair<int, int> > unvisited;
      unvisited.push(make_pair(i,j));
      visited[i][j] = true;
      pair<int, int> result_pair(-1,-1);
      while(!unvisited.empty()){
        pair<int, int> tmp=unvisited.front();
        unvisited.pop();
        if(matrix[tmp.first][tmp.second] == 0){
          result_pair = tmp;
          break;
        }
        for(int k = 0; k !=4; k++){
          pair<int, int> adj;
          adj.first = tmp.first + a[k][0];
          adj.second = tmp.second + a[k][1];
          if(adj.first >= 0 && adj.first < row
             && adj.second >= 0 && adj.second < col
             && !visited[adj.first][adj.second]){
            unvisited.push(adj);
            visited[adj.first][adj.second]=true;
          }
        }
      }
      result[i][j] = abs(result_pair.first - i) + abs(result_pair.second - j);
    }
  return result;
}

int main()
{
  int a[]={0,1,1,1,1};
  vector<int> array(a,a+5);
  vector<vector<int> > mat(5,array);
  vector<vector<int> > result = updateMatrix(mat);
  cout<<"origin: "<<endl;
  for(int i = 0; i != 5; i++){
    for(int j = 0; j != 5; j++)
      cout<<mat[i][j]<<",";
    cout<<endl;
  }
  cout<<"result: "<<endl;
  for(int i = 0; i != 5; i++){
    for(int j = 0; j != 5; j++)
      cout<<result[i][j]<<",";
    cout<<endl;
  }
  return 1;
}
