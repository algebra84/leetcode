/* 464. Can I Win */
#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool win_1(string visited,
           unordered_map<string,bool> &mmap,
           int total){
  if(mmap.count(visited))
    return mmap[visited];
  bool flag = true;
  for(int i = visited.size()-1; i != -1; i--){
    if(visited[i] == '1')
      continue;
    if((i+1) >= total){
      visited[i] = '1';
      mmap[visited] = true;
      return true;
    }
    visited[i] = '1';
    flag = win_1(visited,mmap,total-i-1);
    visited[i] = '0';
    if(!flag)
      break;
  }
  mmap[visited]=!flag;
  return mmap[visited];
}
    
bool canIWin(int maxChoosableInteger, int desiredTotal) {
  string visited(maxChoosableInteger,'0');
  unordered_map<string,bool> mmap;
  if((maxChoosableInteger+1)*maxChoosableInteger/2 < desiredTotal)
    return false;
  return win_1(visited,mmap,desiredTotal);
}
int main()
{
  cout<<canIWin(20,210)<<endl;
  return 1;
}
