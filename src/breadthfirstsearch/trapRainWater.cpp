/*Trapping Rain Water II
  Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

  Note:
  Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

  Example:

  Given the following 3x6 height map:
  [
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
  ]

  Return 4.
*/

#include<vector>
#include<queue>
#include<iostream>
#include <algorithm>
using namespace std;

int trapRainWater(vector<vector<int> >& heightMap){
  typedef pair<int,int> cell;
  priority_queue<cell, vector<cell>, greater<cell> > bar;
  int row = heightMap.size();
  int sum = 0;
  if(0 == row)
    return 0;
  int col = heightMap[0].size();
  vector<int> visited(col*row, 0);
  for(int i = 0; i != row; i++)
    for(int j = 0; j != col; j++)
      if(0 == i || 0 == j || row -1 == i || col - 1 == j){
        bar.push(cell(heightMap[i][j], i*col+j));
        visited[i*col+j] = 1;
      }

  int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
  while(bar.size()){
    cell lowest = bar.top();
    bar.pop();
    for(int i = 0; i != 4; i++){
      int x = lowest.second/col + dir[i][0];
      int y = lowest.second%col + dir[i][1];
      if(x < 0 || x >= row || y < 0 || y >= col || visited[x*col+y])
        continue;
      sum += max(0,lowest.first - heightMap[x][y]);
      visited[x*col+y] = 1;
      bar.push(cell(max(heightMap[x][y],lowest.first), x*col+y));
    }
  }
  return sum;
}

int main()
{
  int p1[]={1,4,3,1,3,2};
  int p2[]={3,2,1,3,2,4};
  int p3[]={2,3,3,2,3,1};
  vector<int> v1(p1,p1+6);
  vector<int> v2(p2,p2+6);
  vector<int> v3(p3,p3+6);
  vector<vector<int> > src;
  src.push_back(v1);
  src.push_back(v2);
  src.push_back(v3);
  cout<<trapRainWater(src)<<endl;
}


