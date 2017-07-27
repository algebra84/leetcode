/* 413. Arithmetic Slices */
#include<vector>
#include<iostream>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
  if(A.size() < 3)
    return 0;
  int count = 0;
  int prev = A[0];
  int prev_count = 1;
  int prev_delta;
  for(int i = 1; i != A.size(); i++){
    if(i == 1)
      prev_delta = A[i]-prev;
    else
      if(A[i]-prev == prev_delta)
        prev_count++;
      else{
        if(prev_count > 1)
          count+=(prev_count)*(prev_count-1)/2;
        prev_count = 1;
        prev_delta = A[i]-prev;
      }
    prev = A[i];
  }
  if(prev_count > 1)
    count+=(prev_count)*(prev_count-1)/2;
  return count;
}
int main()
{
  int a[]={1,2,3,8,9,10};
  vector<int> A(a,a+6);
  cout<<numberOfArithmeticSlices(A)<<endl;
  return 1;
}
