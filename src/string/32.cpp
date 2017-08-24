/* 32. Longest Valid Parentheses */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int longestValidParentheses(string s){
  int res = 0;
  vector<int> mvec;
  for(int i = 0; i != s.size(); i++){
    if(mvec.empty()){
      mvec.push_back(i);
      continue;
    }
    if(s[i] == '(')
      mvec.push_back(i);
    else
      if(s[mvec.back()] == '('){
        mvec.pop_back();
        if(mvec.empty())
          res = max(res,i+1);
        else
          res = max(res,(i-mvec.back()));
      }
      else
        mvec.push_back(i);
  }
  return  res;
}

int main()
{
  cout<<longestValidParentheses("()(()")<<endl;
}
