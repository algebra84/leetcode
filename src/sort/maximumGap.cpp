/*164. Maximum Gap
  Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

  Try to solve it in linear time/space.

  Return 0 if the array contains less than 2 elements.

  You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

*/
#include<vector>
#include<iostream>
using namespace std;
int maximumGap(vector<int>& nums){
  int N = nums.size();
  int gap,bucketnum;
  if(N < 2)
    return 0;
  int minv = nums[0];
  int maxv = nums[0];
  for(int i = 1; i != N; i++){
    if(nums[i] > maxv)
      maxv = nums[i];
    if(nums[i] < minv)
      minv = nums[i];
  }
  gap = (maxv-minv)/(N-1);
  if(gap == 0)
    gap = 1;
  bucketnum = (maxv-minv)/gap + 1;
  if(bucketnum == 1)
    return 0;
  vector<int> bucketmax(bucketnum,minv);
  vector<int> bucketmin(bucketnum,maxv);
  vector<int> bucketcount(bucketnum,0);
  for(int i = 0; i != N; i++){
    int index = (nums[i]-minv)/gap;
    bucketcount[index]++;
    if(nums[i]>bucketmax[index])
      bucketmax[index] = nums[i];
    if(nums[i]<bucketmin[index])
      bucketmin[index] = nums[i];
  }
  int res = 0;
  int maxi = minv;
  for(int i = 0; i != bucketnum; i++){
    if(bucketcount[i] == 0)
      continue;
    if((bucketmin[i] - maxi)>res)
      res = bucketmin[i]-maxi;
    maxi = bucketmax[i];
  }

  return res;
}

int main()
{
  int a[]={3,6,9,1};
  vector<int> nums(a,a+4);
  cout<<maximumGap(nums)<<endl;
}
