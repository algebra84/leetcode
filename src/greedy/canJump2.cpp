/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Your goal is to reach the last index in the minimum number of jumps.

  For example:
  Given array A = [2,3,1,1,4]

  The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

  Note:
  You can assume that you can always reach the last index.

*/
#include<iostream>
#include<vector>
using namespace std;
int jump(vector<int>& nums){
  int N = nums.size();
  int count = 0;
  int max = 0, premax = -1;
  if(N == 1)
    return 0;
  for(int i=0; i != N; i++){
    if(max < nums[i] +i){
      if (i > premax){
        count++;
        premax = max;
      }
      max = nums[i] + i;
    }
    if (max >= N-1)
      return count;
  }
  return 0;
}

int main()
{
  int a[]={7,1};
  vector<int> mvec(a,a+2);
  cout<<jump(mvec)<<endl;
  return 1;
}
