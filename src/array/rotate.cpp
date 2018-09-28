/* 48. Rotate Image */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int temp;
    if(n < 2)
      return ;
    int iter = n-1;
    int row = 0;
    while(iter > 0){
      for(int j = row; j != n-1-row; j++){
        temp = matrix[row][j];
        matrix[row][j] = matrix[n-1-j][row];
        matrix[n-1-j][row] = matrix[n-1-row][n-1-j];
        matrix[n-1-row][n-1-j] = matrix[j][n-1-row];
        matrix[j][n-1-row] = temp;
      }
      iter-=2;
      row+=1;
    }
    return;
  }
};

int main(){
  int a[6][6]={{1,2,3,4,5,6},{6,7,8,9,10,11},{10,11,12,13,14,15},{15,16,17,18,19,20},{20,21,22,23,24,25}};
  vector<vector<int> > matrix;
  matrix.push_back(vector<int> (a[0],a[0]+6));
  matrix.push_back(vector<int> (a[1],a[1]+6));
  matrix.push_back(vector<int> (a[2],a[2]+6));
  matrix.push_back(vector<int> (a[3],a[3]+6));
  matrix.push_back(vector<int> (a[4],a[4]+6));
  matrix.push_back(vector<int> (a[5], a[5]+6));
  Solution sol;
  sol.rotate(matrix);
  for(int i = 0; i != matrix.size(); i++){
    for(int j = 0; j != matrix[i].size(); j++)
      cout<<matrix[i][j]<<" ";
    cout<<endl;
  }
  return 1;
}
