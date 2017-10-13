/* 34. Search for a Range
   Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

   Your algorithm's runtime complexity must be in the order of O(log n).

   If the target is not found in the array, return [-1, -1].

   For example,
   Given [5, 7, 7, 8, 8, 10] and target value 8,
   return [3, 4]. */

#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target){
  int start=-1,end=-1;
  int low = 0,upper = nums.size();
  while(low < upper){
    int mid = low + (upper-low)/2;
    if(nums[mid] > target)
      upper = mid;
    else if(nums[mid] < target)
      low = mid+1;
    else{
      int i = mid;
      while(nums[i] == target && i != upper)
        i++;
      end = i-1;
      i = mid;
      while(nums[i] == target && i >= low)
        i--;
      start = i+1;
      break;
    }
  }
  vector<int> result;
  result.push_back(start);
  result.push_back(end);
  return result;
}

int main()
{
  int a[]={5,7,7,8,8,10};
  vector<int> nums(a,a+6);
  vector<int> result = searchRange(nums,8);
  for(auto i:result)
    cout<<i<<endl;
  return 1;
}
