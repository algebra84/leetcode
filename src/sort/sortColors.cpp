/*75. Sort Colors
  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.*/

#include<vector>
#include<iostream>
using namespace std;

void sortColors(vector<int>& nums){
  int nums_0 = 0, nums_1 = 0, nums_2 = 0;
  vector<int> result;
  for(int i = 0; i != nums.size(); i++){
    switch(nums[i]){
    case 0:
      nums_0++;
      break;
    case 1:
      nums_1++;
      break;
    case 2:
      nums_2++;
      break;
    }
  }
  while(nums_0 + nums_1 + nums_2){
    if(nums_0){
      result.push_back(0);
      nums_0--;
      continue;
    }
    if(nums_1){
      result.push_back(1);
      nums_1--;
      continue;
    }
    if(nums_2){
      result.push_back(2);
      nums_2--;
    }
  }
  nums = result;
  return;
}

int main()
{
  int a[]={0,1,2,2,1,2,0,0,0,1,2};
  vector<int> nums(a,a+11);
  sortColors(nums);
  for(int i = 0; i != nums.size(); i++)
    cout<<nums[i]<<endl;
  return 1;
}
