/* 5. Longest Palindromic Substring */
#include<string>
#include<vector>
#include<iostream>
using namespace std;
bool is_Palindromic(string s){
  if(s.size() == 0)
    return true;
  int i=0,j = s.size()-1;
  while(i <= j){
    if(s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}
string build_1(string s,int start,int end){
  if(start == end)
    return s.substr(start,1);
  string res1,res2;
  for(int i = end; i != start-1; i--){
    if(s[i] == s[start] && is_Palindromic(s.substr(start,i-start+1))){
      res1 = s.substr(start,i-start+1);
      break;
    }
  }
  res2 = build_1(s,start+1,end);
  return res1.size() > res2.size()?res1:res2;
}
string longestPalindrome(string s) {
  if(s.size() <= 1)
    return s;
  vector<vector<int> > mmap(s.size(),vector<int>(s.size(),-1));
  return build_1(s,0,s.size()-1);
}

int main()
{
  cout<<longestPalindrome("babad")<<endl;
  return 1;
}
