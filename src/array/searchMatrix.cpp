/* 74. Search a 2D Matrix */

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
  static bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int rows = matrix.size();
    if(rows == 0)
      return false;
    int columns = matrix[0].size();
    if(columns == 0)
      return false;
    int mid = rows*columns/2;
    int start = 0, end = rows*columns-1;
    while(1){
      int row = mid/columns;
      int col = mid%columns;
      if(start > end)
        break;
      if(matrix[row][col] == target)
        return true;
      else if(matrix[row][col] < target){
        start = mid+1;
        mid = (start+end)/2;
      }
      else{
        end = mid-1;
        mid = (start+end)/2;
      }
    }
    return false;
  }
};

int main(){
  int a[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
  vector<vector<int> > matrix;
  matrix.push_back(vector<int> (a[0],a[0]+4));
  matrix.push_back(vector<int> (a[1],a[1]+4));
  matrix.push_back(vector<int>(a[2],a[2]+4));
  cout<<Solution::searchMatrix(matrix, 13)<<endl;
  return 1;
}
