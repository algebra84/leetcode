/*200. Number of Islands
  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

  Example 1:

  11110
  11010
  11000
  00000
  Answer: 1

  Example 2:

  11000
  11000
  00100
  00011
  Answer: 3
*/

#include<vector>
#include<iostream>
#include<string>
using namespace std;
int numIslands(vector<vector<char> >& grid){
  int row = grid.size();
  int col = 0;
  int count = 0;
  if(row)
    col = grid[0].size();
  vector<int> visited(row*col, 0);
  int a[][2]={{0,1},{0,-1},{-1,0},{1,0}};
  for(int i = 0; i != row*col; i++){
    if(visited[i])
      continue;
    int y = i%col, x = i/col;
    if(grid[x][y] == '0')
      continue;
    count++;
    vector<int> mstack;
    mstack.push_back(i);
    visited[i] = 1;
    while(mstack.size()){
      int tmp_n = mstack.back();
      bool flag = false;
      for(int j = 0; j != 4; j++){
        int tmp_x = tmp_n/col+a[j][0];
        int tmp_y = tmp_n%col+a[j][1];
        if(tmp_x >= 0 && tmp_x < row
           && tmp_y >= 0 && tmp_y < col
           && grid[tmp_x][tmp_y] != '0'
           && 0 == visited[tmp_x*col+tmp_y]){
          mstack.push_back(tmp_x*col+tmp_y);
          visited[tmp_x*col+tmp_y] = 1;
          flag=true;
          break;
        }
      }
      if(!flag)
        mstack.pop_back();
    }
  }
  return count;
}

int main()
{
  vector<vector<char> > s;
  string t1="11000",t2="11000",t3="00100",t4="00011";
  s.push_back(vector<char>(t1.begin(),t1.end()));
  s.push_back(vector<char>(t2.begin(),t2.end()));
  s.push_back(vector<char>(t3.begin(),t3.end()));
  s.push_back(vector<char>(t4.begin(),t4.end()));
  cout<<numIslands(s)<<endl;
}
