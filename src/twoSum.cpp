/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  Example:
  ---------------------------------------
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
  ---------------------------------------
*/

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  static vector<int> twoSum(vector<int>& nums, int target) {
    size_t size = nums.size();
    vector<int> tmp;
    for(int i = 0; i != size; i++)
      for(int j = i + 1; j != size; j++)
        if (nums[i] + nums[j] == target)
          {
            tmp.push_back(i);
            tmp.push_back(j);
            return tmp;
          }

    return tmp;
  }
};

int main()
{
  int a[3] = {3,2,4};
  vector<int> problem(a, a+3);
  vector<int> _solution = Solution::twoSum(problem, 6);
  cout<<"solution: "<<_solution[0]<<" and "<<_solution[1]<<endl;
}
