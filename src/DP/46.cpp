#include<vector>
#include<iostream>
#include<set>
using namespace std;
void permute_build_1(vector<int>& cand, vector<vector<int> >&result,
                     set<int>& mset,vector<int>& nums){
  if(mset.size() == nums.size()){
    result.push_back(cand);
    return;
  }
  for(int i = 0; i != nums.size(); i++){
    if(mset.count(i))
      continue;
    mset.insert(i);
    cand.push_back(nums[i]);
    permute_build_1(cand,result,mset,nums);
    mset.erase(i);
    cand.pop_back();
  }
  return;
}
vector<vector<int> > permute(vector<int>& nums) {
  vector<vector<int> > result;
  vector<int> cand;
  set<int> mset;
  permute_build_1(cand,result,mset,nums);
  return result;
}

int main()
{
  int a[]={1,2,3};
  vector<int> nums(a,a+3);
  vector<vector<int> > res = permute(nums);
  for(int i = 0; i != res.size(); i++){
    for(int j = 0; j != res[i].size(); j++)
      cout<<res[i][j]<<",";
    cout<<endl;
  }
  return 1;
}
