/* 71. Simplify Path */

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
  bool isChar(char s){
    return (s>='a' && s <= 'z')||(s>='A' && s<='Z');
  }
  string simplifyPath(string path) {
    vector<string> res;
    int start = -1, end = -1;
    path+="/";
    for(int i = 0; i != path.size(); i++){
      if(path[i]=='/'){
        end = i;
        if(start + 1 == end){
          start = end;
          continue;
        }
        string tmp(path,start, end-start);
        if(!tmp.compare("/..")){
          if(res.size())
            res.pop_back();
        }
        else if(!tmp.compare("/."))
          ;
        else
          res.push_back(tmp);
        start = end;
        continue;
      }
    }
    string ress;
    if(!res.size())
      return "/";
    for(int i = 0; i != res.size(); i++)
      ress+=res[i];
    return ress;
  }
};

int main(){
  string path("/home");
  Solution sol;
  cout<<sol.simplifyPath(path)<<endl;
}
