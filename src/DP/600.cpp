/* 600. Non-negative Integers without Consecutive Ones */

#include<vector>
#include<iostream>
using namespace std;
int findIntegers(int num) {
  int res = 0;
  for(int i = 0; i != num+1; i++){
    cout<<"i: "<<i<<", i>>1: "<<(i>>1)<<", i&i>>1: "<<(i&(i/2))<<endl;
    int tmp = (int)(i&(i/2));
    if(tmp == 0)
      res++;
  }
      
  return res;
}

int main()
{
  cout<<findIntegers(31)<<endl;
}
