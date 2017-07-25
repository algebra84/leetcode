/* 553. Optimal Division */
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;
double optimal_max(vector<int>& nums, int start,int end,
                unordered_map<int,char>& mmap);
double optimal_min(vector<int>& nums, int start,int end,
                unordered_map<int,char>& mmap){
  if(start == end-1)
    return nums[start];
  if(start == end-2)
    return (double)nums[start]/(double)nums[start+1];
  double result = 1000.0;
  unordered_map<int,char> tmp = mmap;
  unordered_map<int,char> opt = mmap;
  for(int i = start+1; i != end; i++){
    mmap = tmp;
    double m = optimal_min(nums,start,i,mmap);
    if(i != end-1){
      mmap[i] = '(';
      mmap[end] = ')';
    }
    double n = optimal_max(nums,i,end,mmap);
    if(m/n < result){
      opt = mmap;
      result = m/n;
    }
  }
  return result;
}
double optimal_max(vector<int>& nums, int start,int end,
                unordered_map<int,char>& mmap){
  if(start == end-1)
    return nums[start];
  if(start == end-2)
    return (double)nums[start]/(double)nums[end-1];
  double result = 0.0;
  unordered_map<int, char> tmp = mmap;
  unordered_map<int,char> opt = mmap;
  for(int i = start+1; i != end; i++){
    mmap = tmp;
    double m = optimal_max(nums,start,i,mmap);
    if(i != end-1){
      mmap[i]='(';
      mmap[end]=')';
    }
    double n = optimal_min(nums,i,end,mmap);
    if(m/n > result){
      result = m/n;
      opt=mmap;
    }
  }
  mmap = opt;
  return result;
}

string optimalDivision(vector<int>& nums) {
  unordered_map<int,char> mmap;
  string result;
  int size = nums.size();
  if(size == 0)
    return result;
  cout<<optimal_max(nums,0,nums.size(),mmap)<<endl;
  for(int i = 0; i != size; i++){
    if(mmap.count(i) && mmap[i] == '(')
      result+=mmap[i];
    result+=to_string(nums[i]);
    if(mmap.count(i+1) && mmap[i+1]==')')
      result+=")/";
    else
      result+='/';
  }
  if(result[result.size()-1] = '/')
    result.erase(result.size()-1,1);
  return result;
}

int main()
{
  int a[]={1000,100,10,2};
  vector<int> nums(a,a+4);
  cout<<optimalDivision(nums)<<endl;
  return 1;
}
