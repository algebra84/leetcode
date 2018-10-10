/* 91. Decode Ways */

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
  map<string, int> mmap;
  int numDecodings(string s){
    if(s.size() == 0)
      return 0;
    return numDecodings1(s);
  }
  int numDecodings1(string s) {
    if(s.size() == 0)
      return 1;
    if(s[0] == '0')
      return 0;
    if(s.size() == 1)
      return 1;
    if(mmap.count(s) > 0)
      return mmap[s];
    if(s[0] == '1'
       || (s[0]=='2' && s[1] >= '0' && s[1] <= '6')){
      string tmp1(s, 1, s.size() - 1);
      string tmp2(s, 2, s.size() - 2);
      int count1 = numDecodings1(tmp1);
      int count2 = numDecodings1(tmp2);
      mmap[s] = count1+count2;
      return count1+count2;
    }
    int res = numDecodings1(string(s, 1, s.size()-1));
    mmap[s] = res;
    return res;
  }
};

int main(){
  string s("203");
  Solution sol;
  cout<<sol.numDecodings(s)<<endl;
  return 1;
}
