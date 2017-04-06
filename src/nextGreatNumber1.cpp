/*You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/

#include<vector>
#include<iostream>
using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
  int size1 = findNums.size(), size2 = nums.size();
  bool right = false;
  vector<int> result(findNums.size(), -1);
  for(int i = 0; i != size1; i++){
    right = false;
    for(int j = 0; j != size2; j++){
      if(!right && (findNums[i] == nums[j])){
        right = true;
        continue;
      }
      if(right && findNums[i] < nums[j]){
        result[i] = nums[j];
        break;
      }
    }
  }
  return result;
}

int main()
{
  int a[]={4,1,2}, b[]={1,3,4,2};
  vector<int> num1(a,a+3), num2(b, b+4);
  vector<int> result = nextGreaterElement(num1,num2);
  for(int i = 0; i != result.size(); i++)
    cout<<result[i]<<endl;
}
