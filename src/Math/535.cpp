/* 535. Encode and Decode TinyURL */
#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
  unordered_map<string,string> mmap;
  vector<string> url_vec;
  string base;
  Solution():base("http://tinyurl.com/"){}
  char map62(int index){
    if(index < 10) return '0'+index;
    if(index < 36) return 'a'+index-10;
    return 'A'+index-36;
  }
  int rev62(char c){
    if(c>='0' && c<='9') return c-'0';
    if(c>='a' && c<='z') return c-'a'+10;
    if(c>='A' && c<='Z') return c-'A'+36;
  }
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if(mmap.count(longUrl) > 0)
      return mmap[longUrl];
    url_vec.push_back(longUrl);
    string res = base;
    int count = url_vec.size()-1;
    while(count){
      res+=map62(count%62);
      count/=62;
    }
    mmap[longUrl] = res;
    return res;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string tmp = shortUrl.substr(19);
    int count = 0;
    for(int i = tmp.size()-1; i != -1; i--)
      count = count*62+rev62(tmp[i]);
    return url_vec[count];
  }
};

int main()
{
  Solution obj;
  cout<<obj.encode("https://leetcode.com/problems/design-tinyurl")<<endl;
  cout<<obj.decode(obj.encode("https://leetcode.com/problems/design-tinyurl"))<<endl;
  return 1;
}
