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
  vector<vector<int> > result(row, vector<int>(col, -1));
  vector<vector<bool> > visited(row, vector<bool>(col, false));
  queue<pair<int,int> > unvisited;
  for(int i = 0; i != row; i++)
    for(int j = 0; j != col; j++){
      if(matrix[i][j] == 0){
        visited[i][j] = true;
        result[i][j] = 0;
        unvisited.push(make_pair(i, j));
      }
    }
  while(unvisited.size()){
    pair<int, int> tmp = unvisited.front();
    unvisited.pop();
    for(int k = 0; k !=4; k++){
      pair<int, int> adj;
      adj.first = tmp.first + a[k][0];
      adj.second = tmp.second + a[k][1];
      if(adj.first >= 0 && adj.first < row
         && adj.second >= 0 && adj.second < col
         && !visited[adj.first][adj.second]){
        unvisited.push(adj);
        visited[adj.first][adj.second]=true;
        result[adj.first][adj.second] = result[tmp.first][tmp.second] + 1;
      }
    }
  }
  return result;
}

int main()
{
  int a[]={0,1,0,1,1};
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
