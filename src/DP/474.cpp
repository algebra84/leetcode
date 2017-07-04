/* 474. Ones and Zeroes */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
int find_1(vector<vector<int> > &cube,int m, int n,int index,
           unordered_map<string,int>& mmap){
  if(index == cube.size())
    return 0;
  if(m == 0 && n == 0)
    return 0;
  string key = to_string(m)+" "+to_string(n)+" "+to_string(index);
  if(mmap.count(key))
    return mmap[key];
  int res = 0;
  int max_m = (m+n),max_n = (m+n);
  if(cube[index][2]!= 0)
    max_m = m/cube[index][2];
  if(cube[index][3]!=0)
    max_n = n/cube[index][3];
  for(int i = index; i != cube.size();i++){
    if(m-cube[i][0] >= 0 && n-cube[i][1]>=0)
      res = max(res,1+find_1(cube,m-cube[i][0],n-cube[i][1],
                             i+1,mmap ));
    if(res == min(max_n,max_n))
      break;
  }
  mmap[key]=res;
  return res;
}
int findMaxForm(vector<string>& strs, int m, int n){
  int size = strs.size();
  vector<vector<int> > cube(size,vector<int>(4,0));
  int min_m = 1000,min_n = 1000;
  for(int i = 0; i != strs.size(); i++){
    int m0=0,n1=0;
    for(int j = 0; j != strs[i].size();j++)
      if(strs[i][j] == '0')
        m0++;
      else
        n1++;
    cube[i][0] = m0;
    cube[i][1] = n1;
  }
  for(int i = cube.size()-1; i != -1; i--){
    min_m = min(min_m,cube[i][0]);
    min_n = min(min_n,cube[i][1]);
    cube[i][2] = min_m;
    cube[i][3] = min_n;
  }
  unordered_map<string,int> mmap;
  return find_1(cube,m,n,0,mmap);
}
int main()
{
  string s[]={"0","0","0","0","0","1","1","0","1","1","1","0","1","0","1","1","0","0","1","0","1","1","0","1","1","1","1","1","0","1","1","1","1","1","1","0","1","1","0","0","0","0","1","1","0","1"};
  vector<string> strs(s,s+46);
  cout<<findMaxForm(strs,52,12)<<endl;
}
