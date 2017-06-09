/*
  347. Top K Frequent Elements
*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
  map<int,int> mmap;
  vector<int> result;
  multimap<int,int> multi;
  for(int i = 0; i != nums.size(); i++)
    mmap[nums[i]]++;
  for(map<int,int>::iterator it = mmap.begin(); it != mmap.end(); it++)
    multi.insert(make_pair(it->second,it->first));
  int count = 0;
  for(multimap<int,int>::reverse_iterator it = multi.rbegin(); it != multi.rend(); it++){
    if(count == k)
      break;
    result.push_back(it->second);
    count++;
  }
  return result;
}

int main()
{
  int a[]={1,1,1,2,2,3};
  vector<int> nums(a,a+6);
  vector<int> res=topKFrequent(nums,2);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<endl;
  return 1;
}
