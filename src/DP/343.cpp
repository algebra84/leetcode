/* 343. Integer Break */
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<int,int> mmap;
int build_1(int n){
  if(n <= 4)
    return n;
  if(mmap[n])
    return mmap[n];
  int result = 0;
  for(int i = 2; i != n; i++)
    result = max(result,i*build_1(n-i));
  mmap[n] = result;
  return result;
}
int integerBreak(int n){
  int result = 0;
  for(int i = 1; i != n; i++)
    result =max(result,i*build_1(n-i));
  return result;
}

int main()
{
  cout<<integerBreak(58)<<endl;
  return 1;
}
