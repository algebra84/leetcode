/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Determine if you are able to reach the last index.

  For example:
  A = [2,3,1,1,4], return true.

  A = [3,2,1,0,4], return false. */

#include<iostream>
#include<vector>
using namespace std;
bool canJump(vector<int>& nums){
  int N = nums.size();
  int max = 0;
  if(N == 0)
    return false;
  for(int i = 0; i != N; i++){
    if(max >= i && max < nums[i] + i)
      max = nums[i] + i;
    if(max < i)
      return false;
    if(max >= N-1)
      return true;
  }
  return false;
}

int main()
{
  int a[]={3,2,1,0,4};
  vector<int> mvec(a,a+5);
  cout<<canJump(mvec)<<endl;
}

