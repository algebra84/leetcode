/* 30. Substring with Concatenation of All Words */
#include<unordered_map>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {
  unordered_map<string,int> index_map;
  unordered_map<string,int> exist_map;
  vector<int> result;
  if(words.size() == 0 || words[0].size() == 0
     || words.size()*words[0].size() > s.size())
    return result;
  for(int i = 0; i != words.size(); i++){
    index_map[words[i]] = i;
    exist_map[words[i]]++;
  }
  int wordslen = words.size()*words[0].size();
  for(int i = 0; i != s.size()-wordslen+1; i++){
    string sub = s.substr(i,wordslen);
    vector<int> erase_list;
    for(int j = 0; j != words.size(); j++){
      string tmp = sub.substr(j*words[0].size(),words[0].size());
      if(exist_map.count(tmp) > 0){
        exist_map[tmp]--;
        if(exist_map[tmp] == 0)
          exist_map.erase(tmp);
        erase_list.push_back(index_map[tmp]);
      }
      else
        break;
    }
    if(exist_map.empty())
      result.push_back(i);
    for(auto it:erase_list)
      exist_map[words[it]]++;
  }
  return result;
}

int main()
{
  string s="barfoothefoobarman";
  string a[]= {"bar","foo"};
  vector<string> words(a,a+2);
  vector<int> res = findSubstring(s,words);
  for(auto id:res)
    cout<<id<<',';
  cout<<endl;
}
