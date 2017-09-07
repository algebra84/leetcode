/* 29. Divide Two Integers */
#include<iostream>
using namespace std;
int abs(int a){
  if(a == -2147483648)
    return 2147483647;
  if(a < 0)
    return 0-a;
  return a;
}
int divide(int dividend, int divisor){
  int result=0;
  int pos = 0;
  if((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0))
    pos = 1;
  long long dividend1 = abs(dividend);
  long long divisor1 = abs(divisor);
  while(dividend1 >= divisor1){
    long long tmp = divisor1;
    long long cal = 1;
    while(dividend1 >= (tmp<<1)){
      tmp<<=1;
      cal<<=1;
    }
    result+=cal;
    dividend1 -= tmp;
  }
  if(pos == 0)
    result = 0-result;
  return result;
}

int main()
{
  cout<<divide(-2147483648,-1)<<endl;
  return 1;
}
