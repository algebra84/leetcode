/* 120. Triangle */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  static int minimumTotal(vector<vector<int> >& triangle){
    int n = triangle.size();
    if(n == 0)
      return 0;
    if(n == 1)
      return triangle[0][0];
    vector<vector<int> > dp;
    for(int i = 0; i != n; i++)
      dp.push_back(vector<int> (i+1, 2147483647));
    dp[0][0] = triangle[0][0];
    for(int i = 0; i != dp.size() - 1; i++){
      for(int j = 0; j != dp[i].size(); j++){
        int tmp1 = dp[i][j] + triangle[i+1][j];
        int tmp2 = dp[i][j] + triangle[i+1][j+1];
        if(dp[i+1][j] > tmp1)
          dp[i+1][j] = tmp1;
        if(dp[i+1][j+1] > tmp2)
          dp[i+1][j+1] = tmp2;
      }
    }
    int res = dp[n-1][0];
    for(int i = 1; i != dp[n-1].size(); i++){
      res = res > dp[n-1][i] ? dp[n-1][i] : res;
    }
    return res;
  }
};

int main(){
  int a2[2] = {3, 4};
  int a3[3] = {6, 5, 7};
  int a4[4] = {4, 1, 8, 3};
  vector<vector<int> > tr;
  tr.push_back(vector<int> (1, 2));
  tr.push_back(vector<int> (a2, a2+2));
  tr.push_back(vector<int> (a3, a3+3));
  tr.push_back(vector<int> (a4, a4+4));
  cout<<Solution:: minimumTotal(tr)<<endl;
}
