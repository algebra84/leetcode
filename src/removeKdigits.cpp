/*Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

  Note:
  The length of num is less than 10002 and will be ≥ k.
  The given num does not contain any leading zero.
  Example 1:

  Input: num = "1432219", k = 3
  Output: "1219"
  Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
  Example 2:

  Input: num = "10200", k = 1
  Output: "200"
  Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
  Example 3:

  Input: num = "10", k = 2
  Output: "0"
  Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/
#include<vector>
#include<iostream>
using namespace std;

string removeKdigits(string num, int k){
  int N = num.size();
  if(k == 0)
    return num;
  if(k == N)
    return "0";

  while(k > 0){
    int idx = N-1;
    for(int i = 0; i != N-1; i++)
      if(num[i] > num[i+1]){
        idx = i;
        break;
      }
    num.erase(idx,1);
    while(num[0] == '0' && num.size() > 0)
      num.erase(0,1);
    if(num.size() == 0){
      num = "0";
      return num;
    }
    k--;
  }
  return num;
}

int main()
{
  cout<<removeKdigits("222222222222222222222210", 12)<<endl;
  cout<<removeKdigits("10200", 1)<<endl;
  cout<<removeKdigits("10", 2)<<endl;
}
