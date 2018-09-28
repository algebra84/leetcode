/* 49. Group Anagrams */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    map<string, int> mmap;
    vector<vector<string > > res;
    for(int i = 0; i != strs.size(); i++){
      string temp(strs[i]);
      sort(temp.begin(),temp.end());
      if(mmap.count(temp)){
        res[mmap[temp]].push_back(strs[i]);
      }
      else{
        res.push_back(vector<string>(1, strs[i]));
        mmap[temp] = res.size()-1;
      }
    }
    return res;
  }
};


int main(){
  string s[6]={"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<string> strs(s, s+6);
  Solution sol;
  vector<vector<string> > ress = sol.groupAnagrams(strs);
  for(int i = 0; i != ress.size(); i++){
    cout<<"Class "<<i<<" :"<<endl;
    for(int j = 0; j != ress[i].size(); j++)
      cout<<ress[i][j]<<"   ";
    cout<<endl;
  }
}
