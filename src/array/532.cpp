/* 532. K-diff Pairs in an Array */
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int findPairs(vector<int>& nums, int k) {
  if(k < 0)
    return 0;
  map<int,int> mmap;
  for(int i = 0; i != nums.size(); i++)
    mmap[nums[i]]++;
  int res = 0;
  for(map<int,int>::iterator it = mmap.begin();
      it != mmap.end(); it++){
    if(k == 0)
      if(it->second > 1)
        res++;
      else;
    else
      if(mmap.count(it->first+k) > 0)
        res++;
      else
        ;
  }
  return res;
}
int main()
{
  int a[]={3, 1, 4, 1, 5};
  vector<int> va(a,a+5);
  cout<<findPairs(va,0)<<endl;
  return 1;
}
