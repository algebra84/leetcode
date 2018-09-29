/* 65. Valid Number */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
  bool isDigit(char s){
    return s >= '0' && s <= '9';
  }
  bool isSign(char s){
    return s == '+' || s == '-';
  }
  bool isNumber(string s){
    /* strip nop */
    while(s.size() && s[0] == ' ')
      s.erase(0, 1);
    while(s.size() && s[s.size()-1] == ' ')
      s.erase(s.size()-1,1);

    int e_p = 0;
    bool sign_p = true;
    bool dot_p = true;
    bool int_p = false;
    if(s.size() == 0)
      return false;
    for(int i = 0; i != s.size(); i++){
      if(!isDigit(s[i]) && !isSign(s[i]) && s[i] != 'e' && s[i] != '.')
        return false;
      if(isSign(s[i])){
        if(!sign_p)
          return false;
        sign_p = false;
        continue;
      }
      if(s[i] == 'e'){
        if(e_p != 1)
          return false;
        e_p ++;
        sign_p = true;
        dot_p = false;
        continue;
      }
      if(isDigit(s[i])){
        sign_p = false;
        if(e_p == 0)
          e_p++;
        int_p = true;
        continue;
      }
      if(s[i] == '.'){
        if(!dot_p)
          return false;
        dot_p = false;
        continue;
      }
    }
    if(s[s.size()-1] == 'e')
      return false;
    if(!int_p)
      return false;
    if(isSign(s[s.size()-1]))
      return false;
    return true;
  }
};

int main(){
  Solution s;
  string str("4e+");
  cout<<str<<"    : ";
  cout<<s.isNumber(str)<<endl;
  return 1;
}
