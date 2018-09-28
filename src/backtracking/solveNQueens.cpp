/* 51. N-Queens */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
  vector<vector<string> > res;
  int sizee;
  void valid(vector<vector<int> > &am, int row, int col, int clean){
    int n = sizee;
    if(!clean){
      for(int i = 0; i != sizee;i++){
        am[row][i]+=1;
        am[i][col]+=1;
        if(row+i+1 < n && col+i+1 < n)
          am[row+i+1][col+i+1]+=1;
        if(row+i+1 < n && col-(i+1) >= 0)
          am[row+i+1][col-i-1] += 1;
        if(row-i-1 > 0 && col+i+1<n)
          am[row-i-1][col+i+1]+=1;
        if(row-i-1 > 0 && col -i-1>0)
          am[row-i-1][col-i-1]+=1;
      }
      am[row][col]-=1;
    }
    else{
      for(int i = 0; i != sizee;i++){
        am[row][i]-=1;
        am[i][col]-=1;
        if(row+i+1 < n && col+i+1 < n)
          am[row+i+1][col+i+1]-=1;
        if(row+i+1 < n && col-(i+1) >= 0)
          am[row+i+1][col-i-1] -= 1;
        if(row-i-1 > 0 && col+i+1<n)
          am[row-i-1][col+i+1]-=1;
        if(row-i-1 > 0 && col -i-1>0)
          am[row-i-1][col-i-1]-=1;
      }
      am[row][col]+=1;
    }
    return ;
  }
  void buildM(int row, vector<string> &sm, vector<vector<int> > &am){
    if(row == sizee-1){
      for(int i = 0; i != sizee; i++){
        if(am[row][i] == 0){
          sm[row][i] = 'Q';
          res.push_back(sm);
          sm[row][i] = '.';
        }
      }
      return;
    }
    for(int i = 0; i != sizee; i++){
      if(am[row][i] == 0){
        sm[row][i] = 'Q';
        valid(am, row, i, 0);
        buildM(row+1,sm, am);
        sm[row][i] = '.';
        valid(am, row, i, 1);
      }
    }
    return;
  }
  vector<vector<string> > solveNQueens(int n) {
    sizee = n;
    string s(n, '.');
    vector<string> backt(n, s);
    vector<int> availv(n, 0);
    vector<vector<int> > availm(n, availv);
    buildM(0, backt, availm);
    return res;
  }

};

int main(){
  Solution s;
  vector<vector<string> > res = s.solveNQueens(5);
  for(int i = 0; i != res.size();i++){
    cout<<"----------Start M1: "<<endl;
    for(int j = 0; j != res[i].size(); j++){
      cout<<res[i][j]<<endl;
    }
    cout<<"----------End M1: "<<endl;
  }
  return 1;
}
