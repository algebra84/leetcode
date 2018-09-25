/* 166. Fraction to Recurring Decimal */

#include<iostream>
#include<string>
#include<map>
#include <climits>

using namespace std;
class Solution {
public:
  static string fractionToDecimal(int numerator, int denominator){
    long long integer,rec=-1;
    long long mmod;
    string integerString, decimalString;
    map<long long,int> mmap;
    int index = -1;
    string sign  = "";
    long long num1, deno1;
    if((numerator > 0 && denominator < 0)
       || (numerator < 0 && denominator > 0))
       sign += "-";
    num1 = numerator > 0?numerator:(long long)0-numerator;
    deno1 = denominator > 0?denominator:(long long)0-denominator;
    integer = num1/deno1;
    mmod = num1%deno1;
    while(mmod != 0){
      if(mmap.count(mmod) > 0){
        rec = mmap[mmod];
        break;
      }
      index += 1;
      mmap[mmod] = index;
      mmod *= 10;
      decimalString += to_string(mmod/deno1);
      mmod %= deno1;
    }
    if(index == -1)
      return sign+to_string(integer);
    integerString = to_string(integer);
    if(rec != -1){
      decimalString += ")";
      decimalString.insert(rec, "(");
    }
    return sign+integerString + "." + decimalString;
  }

};

int main(){
  cout<<Solution::fractionToDecimal(INT_MIN, -1)<<endl;
//  cout<<(-1.0/INT_MIN)<<endl;
  return 1;
}
