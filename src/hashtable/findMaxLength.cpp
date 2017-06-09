/*525. Contiguous Array */

#include<vector>
#include<iostream>
#include<map>
using namespace std;
int findMaxLength(vector<int>& nums){
  for(int i = 0; i != nums.size(); i++)
    if(nums[i] == 0)
      nums[i]=-1;
  map<int,int> mmap;
  mmap[0] = -1;
  int res = 0;
  int sum = 0;
  for(int i = 0; i != nums.size(); i++){
    sum += nums[i];
    if(mmap.count(sum) != 0)
      res = max(res, i - mmap[sum]);
    else
      mmap[sum]=i;
  }
  return res;
}

int main()
{
  int a[]={0,1,0,1};
  vector<int> nums(a,a+4);
  cout<<findMaxLength(nums)<<endl;
}
