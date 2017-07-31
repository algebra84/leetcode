/* 621. Task Scheduler */
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int build_1(vector<int>& sortarr,int n, int size){
  int count = 0;
  bool flag = false;
  int delta = n+1;
  int next_size = size;
  for(int i = sortarr.size()-1; i != sortarr.size()-size-1; i--){
    if(delta == 0)
      break;
    sortarr[i]--;
    count++;
    delta--;
    if(sortarr[i] == 0 && !flag){
      if(delta > (i-sortarr.size()+size))
        next_size = (sortarr.size()-1-i);
      else
        next_size = sortarr.size()-1-i+(i-sortarr.size()+size)-delta;
      flag = true;
    }
  }
  if(delta != 0 && next_size != 0)
    count+=delta;
  if(next_size == 0)
    return count;
  sort(sortarr.begin()+sortarr.size()-size,sortarr.end());
  return count+build_1(sortarr, n, next_size);

}
int leastInterval(vector<char>& tasks, int n) {
  unordered_map<char,int> mmap;
  for(auto c:tasks)
    mmap[c]++;
  vector<int> sortarr;
  for(unordered_map<char,int>::iterator it = mmap.begin();
      it != mmap.end();it++)
    sortarr.push_back(it->second);
  sort(sortarr.begin(),sortarr.end());
  return build_1(sortarr, n,sortarr.size());
}
int main()
{
  char A[]={'A','A','A','B','B','B'};
  vector<char> tasks(A,A+6);
  cout<<leastInterval(tasks,0)<<endl;
  return 1;
}
