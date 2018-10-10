/* 153. Find Minimum in Rotated Sorted Array */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  int findMin(vector<int>& nums) {
    int start_index = 0;
    int end_index = nums.size()-1;
    if(nums[0] <= nums[nums.size()-1])
      return nums[0];
    while(start_index < end_index){
      int mid_index = (start_index+end_index+1)/2;
//      cout<<"start: "<<start_index<<"mid: "<<mid_index<<"end: "<<end_index<<endl;
      if(mid_index == end_index)
        return nums[end_index];
      if(nums[mid_index] > nums[start_index])
        start_index = mid_index;
      else
        end_index = mid_index;
    }
    return nums[start_index];
  }

};

int main(){
  int a[]={3,1,2};
  vector<int> nums(a, a+3);
  Solution sol;
  cout<<sol.findMin(nums)<<endl;
  return 1;
}
