/*42. Trapping Rain Water
  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

  For example, 
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;

int trap(vector<int>& height){
  vector<int> result;
  int sum = 0;
  map<int, int> mmap;
  int N = height.size();
  int low;
  for(int i = 0; i != N; i++){
    if(!result.size()){
      result.push_back(height[i]);
      mmap[height[i]] = i;
      low = height[i];
      continue;
    }
    if(height[i] < height[i-1]){
      result.push_back(height[i]);
      mmap[height[i]] = i;
      low = height[i];
      continue;
    }
    if(height[i] == height[i-1]){
      mmap[height[i]] = i;
      continue;
    }
    if(height[i] > height[i-1]){
      if(result[0] == low){
        result.clear();
        result.push_back(height[i]);
        mmap[height[i]] = i;
        low = height[i];
        continue;
      }
      while(result.size() && result.back() <= height[i]){
        sum += (result.back()-low)*(i-mmap[result.back()] -1);
        low = result.back();
        result.pop_back();
      }
      if(low < height[i] && result.size())
        sum+=(height[i] - low)*(i-mmap[result.back()]-1);
      result.push_back(height[i]);
      low = height[i];
      mmap[height[i]] = i;
    }
  }
  return sum;
}

int main()
{
  int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> height(a,a+12);
  cout<<trap(height)<<endl;
  return 1;
}
