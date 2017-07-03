/* 486. Predict the Winner*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int score_1(vector<int>& nums, int i, int j,int total,
            vector<vector<int> >& mmap){
  if(j-i == 1)
    mmap[i][j] = nums[i];

  if(j-i == 2)
    mmap[i][j] = max(nums[i],nums[i+1]);

  if(mmap[i][j] != -1)
    return mmap[i][j];
  int s1 = nums[i];
  int s2 = nums[j-1];
  int r1 = score_1(nums,i+1,j,total - s1,mmap);
  int r2 = score_1(nums,i,j-1,total - s2,mmap);
  mmap[i][j] = max(total-r1,total-r2);
  return mmap[i][j];
}

bool PredictTheWinner(vector<int>& nums){
  if(nums.size() < 2)
    return true;
  int total = 0;
  for(int i = 0; i != nums.size(); i++)
    total+=nums[i];
  vector<vector<int> > mmap(nums.size()+1,vector<int>(nums.size()+1,-1));
  int s1 = score_1(nums,0,nums.size(),total,mmap);
  return s1*2>=total;
}

int main()
{
  int a[]={1, 5, 2};
  vector<int> nums(a,a+3);
  cout<<PredictTheWinner(nums)<<endl;
  return 1;
}
