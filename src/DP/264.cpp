/* 264. Ugly Number II */
#include<vector>
#include<iostream>
using namespace std;
int nthUglyNumber(int n){
  if(n == 0)
    return 0;
  vector<int> a(n);
  a[0] = 1;
  int i2=0,i3=0,i5=0;
  for(int i = 1; i != n; i++){
    a[i] = min(a[i2]*2,min(a[i3]*3,a[i5]*5));
    if(a[i] == a[i2]*2)
      i2++;
    if(a[i] == a[i3]*3)
      i3++;
    if(a[i] == a[i5]*5)
      i5++;
  }
  return a[n-1];
}

int main()
{
  for(int i = 1; i != 11; i++)
    cout<<nthUglyNumber(i)<<endl;
  return 1;
}
