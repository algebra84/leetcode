/* 213. House Robber II */

#include<vector>
#include<iostream>
using namespace std;

int build_1(vector<int>& nums,int index,
            vector<int>& mmap0,vector<int> &mmap1,
            bool flag){
  if(flag &&index >= nums.size()-1)
    return 0;
  if(!flag && index >= nums.size())
    return 0;
  if(flag && mmap0[index] != -1)
    return mmap0[index];
  if(!flag && mmap1[index] != -1)
    return mmap1[index];
  int res1 = nums[index] + build_1(nums,index+2,mmap0,mmap1,flag);
  int res2 = build_1(nums,index+1,mmap0,mmap1,flag);
  if(flag)
    mmap0[index] = max(res1,res2);
  else
    mmap1[index] = max(res1,res2);
  return flag?mmap0[index]:mmap1[index];
}
int rob(vector<int>& nums){
  int size = nums.size();
  if(size == 0)
    return 0;
  vector<int> mmap0(size,-1);
  vector<int> mmap1(size,-1);
  return max(nums[0]+build_1(nums,2,mmap0,mmap1,true),
             build_1(nums,1,mmap0,mmap1,false));
}
