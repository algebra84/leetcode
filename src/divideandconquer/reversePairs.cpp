/*493. Reverse Pairs
  Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

  You need to return the number of important reverse pairs in the given array.

  Example1:

  Input: [1,3,2,3,1]
  Output: 2
  Example2:

  Input: [2,4,3,5,1]
  Output: 3
  Note:
  The length of the given array will not exceed 50,000.
  All the numbers in the input array are in the range of 32-bit integer.*/

#include<vector>
#include<iostream>
using namespace std;
int mergeSort(vector<int>& nums, int start, int end){
  if(end - start <=1)
    return 0;
  int mid = start + (end-start)/2;
  int low = mergeSort(nums, start, mid);
  int high = mergeSort(nums, mid, end);
  int low_num = mid-start;
  int high_num = end-mid;
  vector<int> lowv(nums.begin()+start,nums.begin()+mid);
  vector<int> highv(nums.begin()+mid, nums.begin()+end);
  int i = 0,j = 0,k=start;
  int count = 0;
  while(i < (mid-start) || j < (end-mid)){
    if(i == (mid-start)){
      nums[k++] = highv[j++];
      continue;
    }
    if(j == (end-mid)){
      nums[k++] = lowv[i++];
      continue;
    }
    if(lowv[i] <= highv[j]){
      nums[k++]=lowv[i++];
      continue;
    }
    else{
      nums[k++]=highv[j++];
      continue;
    }
  }
  i = 0;
  j = 0;
  while(i <(mid-start) && j < (end-mid)){
    if((long)lowv[i] > 2*(long)highv[j]){
      count+=(mid-start-i);
      j++;
    }
    else
      i++;
  }
  return count+low+high;
}
int reversePairs(vector<int>& nums){
  int N = nums.size();
  if(N == 0)
    return 0;
  return mergeSort(nums,0,nums.size());
}

int main()
{
  int a[]={2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
  vector<int> nums(a,a+6);
  cout<<reversePairs(nums)<<endl;
}
