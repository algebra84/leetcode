/*524. Longest Word in Dictionary through Deleting
  Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

  Example 1:
  Input:
  s = "abpcplea", d = ["ale","apple","monkey","plea"]

  Output: 
  "apple"
  Example 2:
  Input:
  s = "abpcplea", d = ["a","b","c"]

  Output: 
  "a"
  Note:
  1. All the strings in the input will only contain lower-case letters.
  2. The size of the dictionary won't exceed 1,000.
  3. The length of all the strings in the input won't exceed 1,000.*/

#include<string>
#include<vector>
#include<iostream>
using namespace std;
string findLongestWord(string s, vector<string>& d){
  string result;
  for(int i = 0; i != d.size(); i++){
    int j = 0;
    int k = 0;
    while(j < s.size() && k < d[i].size()){
      if(s[j] == d[i][k])
        k++;
      j++;
    }
    if(k == d[i].size())
      if(result.size() < d[i].size())
        result = d[i];
      else if(result.size() == d[i].size() && result.compare(d[i]) > 0)
        result = d[i];
  }
  return result;
}

int main()
{
  string s = "bab";
  vector<string> d;
  d.push_back("ba");
  d.push_back("ab");
  d.push_back("a");
  d.push_back("b");
  cout<<findLongestWord(s,d)<<endl;


}
