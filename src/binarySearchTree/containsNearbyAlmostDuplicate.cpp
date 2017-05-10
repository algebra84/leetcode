/*220. Contains Duplicate III
  Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

  Subscribe to see which companies asked this question.*/

#include<set>
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
  set<long> window;
  for(int i = 0; i != nums.size(); i++){
    if(i > k)
      window.erase((long)nums[i-k-1]);
    auto low = window.lower_bound((long)nums[i] - t);
    auto upper = window.upper_bound((long)nums[i] + t);
    if(low != window.end() && abs(*low - nums[i]) <= t)
      return true;
    window.insert(nums[i]);
  }
  return false;
}

int main()
{
  int a[]={1,5,9,13,17,21,25,29,33,37};
  vector<int> nums(a,a+10);
  cout<<containsNearbyAlmostDuplicate(nums,5,3)<<endl;
}
