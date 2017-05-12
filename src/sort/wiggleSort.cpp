/*324. Wiggle Sort II
  Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

  Example:
  (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
  (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

  Note:
  You may assume all input has valid answer.

  Follow Up:
  Can you do it in O(n) time and/or in-place with O(1) extra space?

*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void wiggleSort(vector<int>& nums) {
  vector<int> result(nums);
  sort(result.begin(),result.end());
  int N = nums.size();
  int j = 0, k = (N+1)/2;
  for(int i = N-1; i != -1;i--)
    if(i%2)
      nums[i] = result[k++];
    else
      nums[i] = result[j++];
  return;
}

int main()
{
  int a[] = {4,5,5,6};
  vector<int> nums(a,a+4);
  wiggleSort(nums);
  for(int i = 0; i != nums.size(); i++)
    cout<<nums[i]<<endl;
  return 1;
}
