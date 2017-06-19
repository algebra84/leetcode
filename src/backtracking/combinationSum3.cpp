/* 216. Combination Sum III */
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > result;
void combinationSum3_1(int k, int n, int low,  vector<int>& res){
  if(k == 1){
    if(n > low && n <= 9){
      res.push_back(n);
      result.push_back(res);
      res.pop_back();
    }
    return;
  }
  for(int i = low+1; i <= 9; i++){
    res.push_back(i);
    combinationSum3_1(k-1,n-i,i,res);
    res.pop_back();
  }
  return;
}
vector<vector<int> > combinationSum3(int k, int n){
  vector<int> res;
  combinationSum3_1(k, n, 0, res);
  return result;
}

int main()
{
  vector<vector<int> > resu;
  resu = combinationSum3(3,9);
  for(int i = 0; i != resu.size();i++){
    cout<<"[";
    for(int j = 0; j != resu[i].size(); j++)
      cout<<resu[i][j]<<",";
    cout<<"]"<<endl;
  }
  return 1;
}
