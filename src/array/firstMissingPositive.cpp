/* 41. First Missing Positive */

#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
  static int firstMissingPositive(vector<int>& nums) {
    map<int,int> mmap;
    int size = nums.size();
    if(size == 0)
      return 1;
    int res = 1;
    for(int i = 0; i != size; i++)
      mmap[nums[i]] = -1;
    for(int i = 1; i != size+2; i++){
      if(mmap.count(i) == 0)
        return i;
    }
  }
};

int main(){
  int a[]={1,2,3};
  vector<int> nums(a,a+3);
  cout<<Solution::firstMissingPositive(nums)<<endl;
  return 1;
}
