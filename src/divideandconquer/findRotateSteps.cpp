/*514. Freedom Trail
  https://leetcode.com/problems/freedom-trail/#/description
 */
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<iostream>
using namespace std;
int findRotateSteps(string ring, string key){
  map<char, vector<int> > mp;
  int size = ring.size();
  int ksize = key.size();
  for(int i = 0; i != size; i++)
    mp[ring[i]].push_back(i);
  vector<vector<int> > result(ksize+1,vector<int> (size,10000));
  for(int i = 0; i != size; i++)
    result[0][i] = 0;
  vector<int> tmp(1,0);
  for(int i = 1; i <= ksize; i++){
    for(auto it:mp[key[i-1]])
      for(int j = 0; j != tmp.size(); j++){
        int res = min((it+size-tmp[j])%size,(tmp[j]+size-it)%size);
        result[i][it] = min(result[i][it],res + result[i-1][tmp[j]]);
      }
    tmp = mp[key[i-1]];
  }
  int res = 10000;
  for(int i = 0; i != mp[key[ksize-1]].size(); i++)
    res = min(res,result[ksize][mp[key[ksize-1]][i]]);
  return res+ksize;
}

int main()
{
  cout<<findRotateSteps("godding","godding")<<endl;
}
