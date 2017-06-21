/* 39. Combination Sum */
#include<vector>
#include<iostream>
using namespace std;

void comb(vector<int>& candidates,int target, vector<vector<int> > &result,
          vector<int>& cand,int index)
{
  if(target < 0)
    return;
  if(target == 0){
    result.push_back(cand);
    return;
  }
  for(int i = index; i != candidates.size();i++){
    cand.push_back(candidates[i]);
    comb(candidates,target-candidates[i],result,cand,i);
    cand.pop_back();
  }
  return;

}
vector<vector<int> > combinationSum(vector<int>& candidates, int target){
  vector<int> cand;
  vector<vector<int> > result;
  comb(candidates,target,result,cand,0);
  return result;
}

int main()
{
  int a[]={2,3,6,7};
  vector<int> cand(a,a+4);
  vector<vector<int> > res = combinationSum(cand,7);
  for(int i = 0; i != res.size(); i++){
    cout<<"[";
    for(int j = 0; j != res[i].size();j++)
      cout<<res[i][j]<<",";
    cout<<"]"<<endl;
  }
  return 1;
}
