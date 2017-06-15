/*  567. Permutation in String */

#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
bool checkInclusion(string s1, string s2){
  unordered_map<char,int> mmap,mmap_tmp;
  unordered_map<char,int> mmap_pos;
  for(int i = 0; i != s1.size(); i++)
    mmap[s1[i]]++;
  int count = 0;
  mmap_tmp = mmap;
  for(int i = 0; i != s2.size(); i++)
    if(mmap_tmp[s2[i]] > 0){
      if(mmap_pos[s2[i]] == 0)
        mmap_pos[s2[i]] = i;
      mmap_tmp[s2[i]]--;
      count++;
      if(count == s1.size())
        return true;
    }
    else{
      if(count != 0){
        if(mmap_pos.count(s2[i]) != 0){
          i = mmap_pos[s2[i]];
          count = 0;
          mmap_pos.clear();
          mmap_tmp = mmap;
        }
        else{
          mmap_tmp = mmap;
          mmap_pos.clear();
          count = 0;
        }
      }
    }
  return false;
}

int main()
{
  string s1 = "adc",s2 = "dcda";
  cout<<checkInclusion(s1,s2)<<endl;
}
