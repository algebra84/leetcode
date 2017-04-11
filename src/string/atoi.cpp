/*Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.*/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
  static int myAtoi(string str) {
    int result = 0;
    int positive = 1;
    int i = 0;
    while(str[i] == ' ')
      i++;
    if(str[i] == '-'){
      positive = -1;
      i++;
    }
    else if(str[i] == '+'){
      positive = 1;
      i++;
    }
    else
      ;
    for(; i != str.size(); i++){
      if((int)str[i] <= 57 && (int)str[i] >= 48){
        if (result > 214748364){
          if(positive == 1)
            return 2147483647;
          else
            return -2147483648;
        }
        else if(result == 214748364){
          if(positive == 1 && (int)str[i] - 48 >= 7)
            return 2147483647;
          else if(positive == -1 && (int)str[i] - 48 >= 8)
            return -2147483648;
        }
        else
          ;
        result = result*10 + ((int)str[i] - 48);
      }
      else
        return result * positive;
    }
    return result * positive;
  }
};

int main()
{
  string number = "1";
  cout<<Solution::myAtoi(number)<<endl;

}
