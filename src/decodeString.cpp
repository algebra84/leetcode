/*Given an encoded string, return it's decoded string.

  The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

  You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

  Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

  Examples:

  s = "3[a]2[bc]", return "aaabcbc".
  s = "3[a2[c]]", return "accaccacc".
  s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

#include<vector>
#include<iostream>
using namespace std;
string decodeString(string s){
  string result;
  int N=s.size();
  for(int i = 0; i != N; i++){
    if(s[i] != ']')
      result += s[i];
    else{
      string tmp;
      while(result.back() != '['){
        tmp.insert(0,1,result.back());
        result.pop_back();
      }
      result.pop_back();

      int num =0;
      int count = 1;
      while(result.back() >= '0' && result.back() <= '9'){
        num = num + count * (result.back() - '0');
        count*=10;
        result.pop_back();
      }
      for(int j = 0; j != num; j++)
        result+=tmp;
    }
  }
  return result;
}

int main()
{
  string tmp="10[a2[c]]";
  cout<<decodeString(tmp)<<endl;
}
