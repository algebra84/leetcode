/* 416. Partition Equal Subset Sum */
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool can_1(vector<int>& nums,int index,int sum,
           unordered_map<string,bool>& mmap){
  if(sum == 0)
    return true;
  if(index == nums.size())
    return false;
  bool flag = false;
  string key = to_string(index)+" "+to_string(sum);
  if(mmap.count(key))
    return mmap[key];
  for(int i = index; i != nums.size();i++){
    if(sum < nums[i])
      continue;
    if(can_1(nums,i+1,sum-nums[i],mmap)){
      flag = true;
      break;
    }
  }
  mmap[key] = flag;
  return flag;
}
bool canPartition(vector<int>& nums){
  int n = nums.size();
  int sum = 0;
  string key(n,0);
  unordered_map<string,bool> mmap; 
  for(auto i:nums)
    sum += i;
  if(sum%2 == 1)
    return false;
  return can_1(nums,0,sum/2,mmap);
}

int main()
{
  int a[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100};
  vector<int> nums(a,a+99);
  cout<<canPartition(nums)<<endl;
  return 1;
}
