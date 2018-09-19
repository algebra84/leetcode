/* 78. Subsets */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  static vector<vector<int> > subsets(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int> > res;
    res.push_back(vector<int>());
    if(size == 0)
      return res;
    int end = nums[size-1];
    nums.pop_back();
    res = subsets(nums);
    size = res.size();
    for(int i = 0; i != size; i++){
      vector<int> tmp(res[i]);
      tmp.push_back(end);
      res.push_back(tmp);
    }
    return res;
  }
};

int main(){
  int a[4]={1,2,3,4};
  vector<int> nums(a, a+4);
  vector<vector<int> > res = Solution::subsets(nums);
  for(int i = 0; i != res.size(); i++){
    cout<<"subset "<<i<<" :";
    for(int j = 0; j != res[i].size(); j++)
      cout<<res[i][j]<<",";
    cout<<endl;
  }
}
