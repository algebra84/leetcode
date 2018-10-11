/* 260. Single Number III */
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    unordered_set<int> sset;
    vector<int> res;
    for(int i = 0; i != nums.size(); i++){
      if(!sset.count(nums[i]))
        sset.insert(nums[i]);
      else
        sset.erase(nums[i]);
    }
    for(unordered_set<int>::iterator it=sset.begin(); it != sset.end(); it++)
      res.push_back(*it);
    return res;
  }
};

int main(){
  int a[6]={1,2,1,3,2,5};
  vector<int> nums(a,a+6);
  Solution sol;
  vector<int> res = sol.singleNumber(nums);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<" ";
  cout<<endl;
}
