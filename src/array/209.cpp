/* 209. Minimum Size Subarray Sum */
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums) {
  queue<int> mqu;
  int result = -1;
  int sum=0,count=0;
  for(auto c:nums){
    mqu.push(c);
    sum+=c;
    count++;
    if(sum >= s){
      while(sum >= s && mqu.size()){
        sum -= mqu.front();
        mqu.pop();
        count--;
      }
      if(result == -1)
        result = count+1;
      else
        result = min(count+1,result);
    }
  }
  return result==-1?0:result;
}
int main()
{
  int a[]={2,3,1,2,4,3};
  vector<int> va(a,a+6);
  cout<<minSubArrayLen(100,va)<<endl;
  return 1;
}
