/* 10. Regular Expression Matching */
#include<string>
#include<iostream>
using namespace std;

bool isMatch(string s, string p) {
  if(s.size() == 0)
    return p.size()==0;
  int i = 0,j = 0;
  while(i != s.size()){
    if(p[j] == '.'){
      i++;
      j++;
      continue;
    }
    if(p[j] == '*'){
      int tmp = i-1;
      while(s[tmp] == s[i-1] && tmp != s.size())
        tmp++;
      while(p[j] == '*' && j != p.size())
        j++;
      if(j == p.size())
        return tmp==s.size();
      if(p[j] == '.'){
        for(int idx = i; idx != tmp+1; idx++){
          if(isMatch(s.substr(idx,s.size()-idx),p.substr(j,p.size()-j)))
            return true;
        }
        return false;
      }
      if(p[j] == s[i-1]){
        for(int idx = i; idx != tmp; idx++){
          if(isMatch(s.substr(idx,s.size()-idx),p.substr(j,p.size()-j)))
            return true;
        }
        return false;
      }
      if(p[j] != s[i-1]){
        if(tmp == s.size())
          return false;
        if(s[tmp] != p[j])
          return false;
        return isMatch(s.substr(tmp,s.size()-tmp),p.substr(j,p.size()-j));
      }
    }
    if(s[i]==p[j]){
      i++;
      j++;
    }
    else
      return false;
  }
  return true;
}

int main()
{
  cout<<isMatch("ab",".*")<<endl;
}
