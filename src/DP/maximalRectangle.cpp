/* 85. Maximal Rectangle */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
  int maxmal1(vector<vector<int> > &maxrows, vector<vector<int> > &maxcols,
              int x, int y){
    int maxrow = maxrows[x][y];
    int maxcol = maxcols[x][y];
    if(maxrow == 0)
      return 0;
    maxrow += x;
    maxcol += y;
    int i = 0;
    int j = 0;
    while(x+i < maxrow && y+j < maxcol){

    }
  }
  int maximalRectangle(vector<vector<char> >& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
      return 0;
    int nrow = matrix.size();
    int ncol = matrix[0].size();
    vector<int> trow(ncol, 0);
    vector<vector<int> > maxrows(nrow, trow);
    vector<vector<int> > maxcols(nrow, trow);
    for(int i = matrix.size()-1; i != -1; i--)
      for(int j = matrix[i].size()-1; j != -1; j--){
        if(matrix[i][j] == '0'){
          maxrows[i][j] = 0;
          maxcols[i][j] = 0;
        }
        else{
          maxrows[i][j] = (i+1 < matrix.size())?maxrows[i+1][j] + 1:1;
          maxcols[i][j] = (j+1 < matrix[i].size())?maxcols[i][j+1] + 1:1;
        }
      }
    int max = 0;
    for(int i = 0; i != nrow; i++)
      for(int j = 0; j != ncol; j++){

      }
  }
};
