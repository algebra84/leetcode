/* Given a string, find the length of the longest substring without repeating characters.

  Examples:

  Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

#include<string>
#include<iostream>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s){
  int max = 0;
  int head = 0;
  map<char, int> hmap;
  int N = s.size();
  if(N == 0)
    return 0;
  for(int i = 0; i != N; i++){
    if(hmap.count(s[i])){
      if(hmap[s[i]] < head){
        hmap[s[i]] = i;
        continue;
      }
      max = (i-head)>max?(i-head):max;
      head = hmap[s[i]]+1;
      hmap[s[i]] = i;
    }
    else
      hmap[s[i]] = i;
  }
  max = (N-head)>max?(N-head):max;
  return max;

}

int main()
{
  string s="tmmzuxt";
  cout<<lengthOfLongestSubstring(s)<<endl;
  return 1;
}
