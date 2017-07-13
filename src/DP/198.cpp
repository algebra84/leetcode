/* 198. House Robber */

#include<vector>
#include<iostream>
using namespace std;
int build_1(vector<int>&nums, int index, vector<int> &mmap){
  if(index >= nums.size())
    return 0;
  if(mmap[index] != -1)
    return mmap[index];
  int res1 = nums[index]+build_1(nums,index+2,mmap);
  int res2 = build_1(nums,index+1,mmap);
  mmap[index] = max(res1,res2);
  return mmap[index];
}

int rob(vector<int>& nums){
  if(nums.size() == 0)
    return 0;
  vector<int> mmap(nums.size(),-1);
  return build_1(nums,0,mmap);
}

