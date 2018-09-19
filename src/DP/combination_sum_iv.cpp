/* 377. Combination Sum IV */
#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
  map<int, int> dpmap;
  int combinationSum4(vector<int>& nums, int target){
    if(dpmap.count(target))
      return dpmap[target];
    int res = 0;
    for(int i = 0; i != nums.size(); i++){
      if(nums[i] == target)
        res+=1;
      else if(nums[i] > target)
        continue;
      else
        res += combinationSum4(nums, target - nums[i]);
    }
    dpmap[target] = res;
    return res;
  }
  Solution(){}
};

int main(){
  int a[8] = {1,2,3,4,5,6,7,8};
  vector<int> nums(a, a+8);
  Solution dp;
  cout<<dp.combinationSum4(nums, 15)<<endl;
}
