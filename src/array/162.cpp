/* 162. Find Peak Element */
#include<vector>
#include<iostream>
using namespace std;
int findPeakElement(vector<int>& nums) {
  if(nums.size()==0)
    return -1;
  if(nums.size() == 1)
    return 0;
  for(int i = 1; i != nums.size(); i++)
    if(nums[i-1] > nums[i])
      return i-1;
  return nums.size()-1;
}

int main()
{
  int a[]={-2147483648, 2, 3, 1};
  vector<int> va(a,a+1);
  cout<<findPeakElement(va)<<endl;
}
