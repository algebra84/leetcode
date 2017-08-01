/* 611. Valid Triangle Number*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int triangleNumber(vector<int>& nums) {
  sort(nums.begin(),nums.end());
  if(nums.size() < 3)
    return 0;
  map<int,int> mmap;
  map<int,int>::iterator it;
  for(int i = 0; i != nums.size(); i++){
    if(mmap.count(nums[i])>0)
      continue;
    else
      mmap[nums[i]]=i;
  }
  int count = 0;
  for(int i = 0; i != nums.size()-2; i++)
    for(int j = i+1; j != nums.size()-1; j++){
      it = mmap.lower_bound(nums[i]+nums[j]);
      if(it != mmap.end())
        count+=max(0,(it->second-j-1));
      else
        count+=(nums.size()-j-1);
    }
  return count;
}

int main()
{
  int a[]={0,0,0,2};
  vector<int> nums(a,a+3);
  cout<<triangleNumber(nums)<<endl;
  return 1;
}
