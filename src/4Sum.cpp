/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

  Note: The solution set must not contain duplicate quadruplets.

  For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

  A solution set is:
  [
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
  ]*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
  static vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    sort(nums.begin(), nums.end());
    size_t size = nums.size();
    for(int i = 0; i != size; i++){
      if(nums[i] > (target/4 + 1))
        break;
      if(i>0 && nums[i] == nums[i-1])
        continue;
      for(int j = i+1; j != size; j++){
        if(nums[j] > (target - nums[i])/3 + 1)
          break;
        if(j>i+1 && nums[j] == nums[j-1])
          continue;
        int k = j+1;
        int m = size -1;
        while(k < m){
          if (nums[i] + nums[j] + nums[k] + nums[m] == target){
            vector<int> tmp;
            tmp.push_back(nums[i]);
            tmp.push_back(nums[j]);
            tmp.push_back(nums[k]);
            tmp.push_back(nums[m]);
            result.push_back(tmp);
            while(nums[k] == nums[k+1]) k++;
            while(nums[m] == nums[m-1]) m--;
            k++;
            m--;
          }
          else if(nums[i] + nums[j] + nums[k] + nums[m] < target)
            k++;
          else
            m--;
        }
      }
    }
    return result;
  }
};

int main()
{
  int a[]={1, 0, -1, 0, -2, 2};
  vector<int> nums(a,a+6);
  vector<vector<int> > result = Solution::fourSum(nums, 0);
  for(int i = 0;i != result.size(); i++){
    cout<<"["<<result[i][0]<<","<<result[i][1]<<","
        <<result[i][2]<<","<<result[i][3]<<"]"<<endl;
  }
      
  return 1;
}
