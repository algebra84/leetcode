/* 523. Continuous Subarray Sum */
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k){
  int n = nums.size();
  if(n < 2)
    return false;
  int sum = 0;
  unordered_set<int> modk;
  int mod = 0, pre = 0;
  for(int i = 0; i != n; i++){
    sum += nums[i];
    mod = (k == 0?sum:sum%k);
    if(modk.count(mod))
      return true;
    modk.insert(pre);
    pre = mod;
  }
  return false;
}

int main()
{
  int a[]={1,1};
  vector<int> nums(a,a+2);
  cout<<checkSubarraySum(nums,2)<<endl;
}
