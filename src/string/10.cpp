/* 10. Regular Expression Matching */
#include<string>
#include<iostream>
#include<vector>
using namespace std;

bool isMatch_1(string s, int id1,
               string p, int id2,
               vector<vector<int> > &mmap)
{
  if(id2 == p.size()){
    if(id1 == s.size())
      return true;
    else
      return false;
  }
  if(id2 == p.size()-1){
    if(id1 != s.size()-1)
      return false;
    if(p[id2] == '.')
      return true;
    return p[id2] == s[id1];
  }
  if(id1 == s.size()){
    if(p[id2+1] != '*')
      return false;
    int tmp = id2+1;
    while(p[tmp]=='*'){
      tmp++;
    }
    if(tmp == p.size())
      return true;
    return false;
  }
  if(p[id2+1] != '*'){
    if(p[id2] = '.')
      return isMatch_1(s,id1+1,p,id2+1,mmap);
    if(p[id2] == s[id1])
      return isMatch_1(s,id1+1,p,id2+1,mmap);
    return false;
  }
  int tmp = id2+1;
  while(p[tmp] == '*')
    tmp++;
  if(p[id2] != '.'){
    int tmp1 = id1;
    if(s[id1] != p[id2])
      return isMatch_1(s,id1,p,tmp,mmap);
    while(s[tmp1] == s[id1])
      tmp1++;
    for(int i = id1; i != tmp1+1; i++){
      if(isMatch_1(s,i,p,tmp,mmap))
        return true;
    }
  }
  for(int i = id1; i != s.size()+1; i++)
    if(isMatch_1(s,i,p,tmp,mmap))
      return true;
  return false;
}

bool isMatch(string s, string p) {
  vector<vector<int> > mmap(s.size(),vector<int> (p.size(), -1));
  return isMatch_1(s,0,p,0,mmap);
}

int main()
{
  cout<<isMatch("ab",".")<<endl;
  cout<<isMatch("aab","c*a*b")<<endl;
  return 1;
}
