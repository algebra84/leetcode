/* 474. Ones and Zeroes */
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int find_1(vector<pair<int,int> > &cube,int m, int n,
           vector<int> &visited){
  int res = 0;
  for(int i = 0; i != visited.size();i++){
    if(visited[i])
      continue;
    visited[i] = 1;
    if(m-cube[i].first >= 0 && n-cube[i].second>=0)
      res = max(res,1+find_1(cube,m-cube[i].first,n-cube[i].second,visited));
    visited[i] = 0;
  }
  return res;
}
int findMaxForm(vector<string>& strs, int m, int n){
  int size = strs.size();
  vector<pair<int,int> > cube;
  for(int i = 0; i != strs.size(); i++){
    int m0=0,n1=0;
    for(int j = 0; j != strs[i].size();j++)
      if(strs[i][j] == '0')
        m0++;
      else
        n1++;
    cube.push_back(make_pair(m0,n1));
  }

  vector<int> visited(size,0);
  return find_1(cube,m,n,visited);
}
int main()
{
  string s[]={"0","1101","01","00111","1","10010","0","0","00","1","11","0011"};
  vector<string> strs(s,s+12);
  cout<<findMaxForm(strs,63,36)<<endl;
}
