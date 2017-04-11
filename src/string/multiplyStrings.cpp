/* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

  Note:

  The length of both num1 and num2 is < 110.
                                        Both num1 and num2 contains only digits 0-9.
                                        Both num1 and num2 does not contain any leading zero.
                                        You must not use any built-in BigInteger library or convert the inputs to integer directly. */

#include<string>
#include<iostream>
#include<vector>

using namespace std;

string multiply(string num1, string num2){
  int size1 = num1.size(), size2 = num2.size();
  int m = 0;
  if(!size1 || !size2)
    return "0";
  vector<char> result(size1+size2, '0');
  int upp = 0;
  for(int i = size1 - 1; i != -1; i--){
    upp = 0;
    for(int j = size2 - 1; j != -1; j--){
      int sum = (int)(num1[i] - '0') * (int)(num2[j] - '0') +
        (int)(result[i+j+1] - '0') + upp;
      upp = sum/10;
      result[i+j+1] = '0' + sum%10;
    }
    result[i] += upp;
  }

  while(result[m] == '0' && m != (size1 + size2 -1))
   m++;
  string r(result.begin() + m, result.end());
  return r;
}

int main()
{
  string n1="9999", n2="0";
  string result = multiply(n1, n2);
  cout<<result<<endl;
}
