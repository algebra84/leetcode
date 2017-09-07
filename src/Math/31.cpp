/* 31. Next Permutation */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums){
  if(nums.size() < 2)
    return;
  int j = -1;
  int k = 0;
  for(int i = nums.size()-2; i != -1; i--){
    if(nums[i] < nums[i+1]){
      k = i+2;
      while(k < nums.size() && nums[i] < nums[k])
        k++;
      j = i;
      k--;
      break;
    }
  }
  if(j == -1)
    sort(nums.begin(),nums.end());
  else{
    int tmp = nums[j];
    nums[j] = nums[k];
    nums[k]=tmp;
    sort(nums.begin()+j+1,nums.end());
  }
  return;
}


int main()
{
  int a[]={1,3,5,4,2};
  vector<int> nums(a,a+5);
  nextPermutation(nums);
  for(auto c:nums)
    cout<<c<<endl;
}
