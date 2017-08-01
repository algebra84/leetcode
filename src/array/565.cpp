/* 565. Array Nesting */
#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
int arrayNesting(vector<int>& nums){
  unordered_set<int> mset;
  int result = 0,count = 0;
  for(int i = 0; i != nums.size(); i++){
    if(mset.count(i) > 0)
      continue;
    int j = i;
    while(mset.count(j)==0){
      count++;
      mset.insert(j);
      j=nums[j];
    }
    result = max(result,count);
    count = 0;
  }
  return result;
}

int main()
{
  int a[]={5,4,0,3,1,6,2};
  vector<int> nums(a,a+7);
  cout<<arrayNesting(nums)<<endl;
  return 1;
}
