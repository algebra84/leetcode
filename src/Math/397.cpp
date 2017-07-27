/* 397. Integer Replacement */
#include<iostream>
#include<unordered_map>
using namespace std;
int build_1(long n,unordered_map<long,int>&mmap){
  if(n == 1)
    return 0;
  if(mmap.count(n)>0)
    return mmap[n];
  if(n%2 == 0)
     mmap[n] = 1+build_1(n/2,mmap);
  else
    mmap[n] = 1+min(build_1(n+1,mmap),build_1(n-1,mmap));
  return mmap[n];

}
int integerReplacement(int n){
  unordered_map<long,int> mmap;
  return build_1(n,mmap);
}

int main()
{
  cout<<integerReplacement(2147483647)<<endl;
  return 1;
}
