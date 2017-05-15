/* 179. Largest Number
   Given a list of non negative integers, arrange them such that they form the largest number.

   For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

   Note: The result may be very large, so you need to return a string instead of an integer.

   Credits:
   Special thanks to @ts for adding this problem and creating all test cases.

   Subscribe to see which companies asked this question.
*/

#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
public:
  static bool mycompare(string s1, string s2){
    string tmp1 = s1+s2;
    string tmp2 = s2+s1;
    if(tmp1.compare(tmp2) > 0)
      return true;
    return false;
  }
  string largestNumber(vector<int>& nums){
    vector<string> arr;
    for(auto i:nums)
      arr.push_back(to_string(i));
    sort(begin(arr), end(arr), Solution::mycompare);
    string res;
    for(auto s:arr)
      res+=s;
    while(res[0]=='0' && res.length()>1)
      res.erase(0,1);
    return  res;
  }
};
int main()
{
  class Solution s1;
  int a[]={97,41,90,86,43,89,43,52,38,5};
  vector<int> nums(a,a+10);
  cout<<s1.largestNumber(nums)<<endl;
  return 1;
}
