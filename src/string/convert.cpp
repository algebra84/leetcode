#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  static string convert(string s, int numRows) {
    string p;
    vector<vector<char> > mstack;
    int i = 0;
    size_t slen = s.length();
    if(numRows < 2 || s.length() <= numRows)
      return s;
    for (int j = 0; j != numRows; j++){
      vector<char> tmp;
      mstack.push_back(tmp);
    }
    for(std::string::iterator it = s.begin(); it != s.end(); ++it){
      int mod = i%(numRows*2 - 2);
      i++;
      if(mod >= numRows)
        mod = numRows*2 - 2 - mod;
      mstack[mod].push_back(*it);
    }

    for(i = 0; i != numRows; i++)
      for(std::vector<char>::iterator it = mstack[i].begin(); it != mstack[i].end(); ++it)
        p+=*it;
    return p;
  }
};

int main(){
  string s = Solution::convert("PAYPALISHIRING", 4);
  cout<<s<<endl;
  return 1;
}
