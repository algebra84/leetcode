/* 423. Reconstruct Original Digits from English */
#include<string>
#include<vector>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<iostream>
using namespace std;
string originalDigits(string s) {
  string result;
  vector<int> nums(10,0);
  vector<int> chars(26,0);
  for(auto c:s)
    chars[c-'a']++;
  nums[0]=chars['z'-'a'];
  nums[8]=chars['g'-'a'];
  nums[6]=chars['x'-'a'];
  nums[7]=chars['s'-'a']-nums[6];
  nums[5]=chars['v'-'a']-nums[7];
  nums[4]=chars['u'-'a'];
  nums[2]=chars['w'-'a'];
  nums[3]=chars['h'-'a']-nums[8];
  nums[1]=chars['o'-'a']-nums[0]-nums[2]-nums[4];
  nums[9]=(chars['n'-'a']-nums[1]-nums[7])/2;
  for(int i = 0;i != 10;i++)
    result = result+string(nums[i],'0'+i);
  return result;
}

int main()
{
  cout<<originalDigits("esnve")<<endl;
  return 1;
}
