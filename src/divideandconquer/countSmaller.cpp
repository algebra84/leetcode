/*315. Count of Smaller Numbers After Self
  You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

  Example:

  Given nums = [5, 2, 6, 1]

  To the right of 5 there are 2 smaller elements (2 and 1).
  To the right of 2 there is only 1 smaller element (1).
  To the right of 6 there is 1 smaller element (1).
  To the right of 1 there is 0 smaller element.
  Return the array [2, 1, 1, 0].*/

#include<vector>
#include<iostream>
#include<set>
using namespace std;
vector<int> countSmaller(vector<int>& nums) {
  multiset<int> mset;
  vector<int> result;
  int N = nums.size();
  for(int i = N-1; i != -1; i--){
    int tmp = nums[i];
    multiset<int>::iterator it=mset.lower_bound(tmp);
    result.insert(result.begin(),distance(mset.begin(),it));
    mset.insert(tmp);
  }
  return result;
}

int main()
{
  int a[]={5,2,6,1};
  vector<int> nums(a,a+4);
  vector<int> res = countSmaller(nums);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<endl;
  return 1;
}
