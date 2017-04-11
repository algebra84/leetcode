/*Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

  For example, given array S = {-1 2 1 -4}, and target = 1.

  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
  static int threeSumClosest(vector<int>& nums, int target) {
    int N = nums.size();
    int delta = nums[0] + nums[1] + nums[2] - target;
    int positive = delta>=0?1:-1;
    delta = delta*positive;
    sort(nums.begin(), nums.end());
    for(int i = 0; i != N; i++){
      if(i>0 && nums[i] == nums[i-1])
        continue;
      int j=i+1, k = N-1;
      while(j<k){
        if(j > i+1 && nums[j] == nums[j-1]){
          j++;
          continue;
        }
        if(k < N-1 && nums[k] == nums[k+1]){
          k--;
          continue;
        }
        if(nums[i] + nums[j] + nums[k] == target)
          return target;
        else if(nums[i] + nums[j] + nums[k] > target){
          if(nums[i] + nums[j] + nums[k] - target < delta){
            delta = nums[i] + nums[j] + nums[k] - target;
            positive = 1;
          }
          k--;
        }
        else{
          if(target - nums[i] - nums[j] - nums[k] < delta){
            delta = target - (nums[i] + nums[j] + nums[k]);
            positive = -1;
          }
          j++;
        }
      }
    }
    return target + positive*delta;
  }
};

int main()
{
  int a[]={1,1,1,1};
  vector<int> nums(a,a+4);
  cout<<Solution::threeSumClosest(nums, 1)<<endl;
}
