/* 467. Unique Substrings in Wraparound String */
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
int findSubstringInWraproundString(string p){
  int size = p.size();
  if(size == 0)
    return 0;
  vector<int> visited(26,0);
  int  maxlength = 0;
  for(int i = 0; i != size; i++){
    if(i != 0 && (p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25))
      maxlength++;
    else
      maxlength = 1;
    visited[p[i]-'a'] = max(visited[p[i]-'a'],maxlength);
  }
  int sum = 0;
  for(int i = 0; i != 26; i++)
    sum += visited[i];
  return sum;
}

int main()
{
  string s("zab");
  cout<<findSubstringInWraproundString(s)<<endl;
  return 1;
}
