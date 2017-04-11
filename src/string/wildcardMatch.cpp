/*Implement wildcard pattern matching with support for '?' and '*'.

  '?' Matches any single character.
  '*' Matches any sequence of characters (including the empty sequence).

  The matching should cover the entire input string (not partial).

  The function prototype should be:
  bool isMatch(const char *s, const char *p)

  Some examples:
  isMatch("aa","a") → false
  isMatch("aa","aa") → true
  isMatch("aaa","aa") → false
  isMatch("aa", "*") → true
  isMatch("aa", "a*") → true
  isMatch("ab", "?*") → true
  isMatch("aab", "c*a*b") → false
 */

#include<string>
#include<iostream>
using namespace std;

bool isMatch(string s, string p){
  int pat = -1, ss = -1;
  int i=0,j=0;
  while(i != s.size()){
    if(j != p.size() && (s[i] == p[j] || p[j] == '?')){
      j++;
      i++;
      continue;
    }
    if(j != p.size() && p[j] == '*'){
      ss = i;
      pat = j++;
      continue;
    }
    if(pat != -1){
      j = pat + 1;
      i = ++ss;
      continue;
    }
    return false;
  }

  while(j != p.size()){
    if(p[j] == '*')
      j++;
    else
      break;
  }
  if(j == p.size())
    return true;
  return false;
}

int main()
{
  cout<<isMatch("abc", "a*c")<<endl;
}
