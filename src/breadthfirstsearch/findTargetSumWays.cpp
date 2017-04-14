/*494. Target Sum
  You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

  Find out how many ways to assign symbols to make sum of integers equal to target S.

  Example 1:
  Input: nums is [1, 1, 1, 1, 1], S is 3. 
  Output: 5
  Explanation: 

  -1+1+1+1+1 = 3
  +1-1+1+1+1 = 3
  +1+1-1+1+1 = 3
  +1+1+1-1+1 = 3
  +1+1+1+1-1 = 3

  There are 5 ways to assign symbols to make the sum of nums be target 3.
  Note:
  The length of the given array is positive and will not exceed 20.
  The sum of elements in the given array will not exceed 1000.
  Your output answer is guaranteed to be fitted in a 32-bit integer.*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
int findTargetSumWays(vector<int>& nums, int S) {
  int N = nums.size();
  int result = 0;
  if(N == 0)
    return 0;
  map<int,int> visited;
  map<int,int> miter;
  visited[nums[0]] += 1;
  visited[0-nums[0]] += 1;
  for(int i = 1; i != N; i++){
    while(visited.size()){
      miter[visited.begin()->first + nums[i]] += visited.begin()->second;
      miter[visited.begin()->first - nums[i]] += visited.begin()->second;
      visited.erase(visited.begin());
    }
    visited = miter;
    miter.clear();
  }
  return visited[S];
}

int main()
{
  int a[]={1,1,1,1,1};
  vector<int> ivec(a,a+5);
  cout<<findTargetSumWays(ivec, 3)<<endl;
  return 1;
  }
