/* 279. Perfect Squares */
#include<cmath>
#include<iostream>
#include<map>

using namespace std;
class Solution {
public:
  map<int,int> dpmap;
  int numSquares(int n) {
    if(dpmap.empty())
      init(n);
    if(dpmap.count(n) > 0)
      return dpmap[n];
    int res = n;
    for(int i = (int)sqrt(n); i != 0; i--){
      int rest = numSquares(n-i*i);
      if(rest + 1 < res)
        res = rest+1;
      if(res == 2)
        break;
    }
    dpmap[n] = res;
    return res;
  }
  void init(int n){
    for(int i = 1; i != (int)sqrt(n) + 1; i++)
      dpmap[i*i] = 1;
  }
  Solution(){}
};

int main()
{
  Solution p;
  for(int i = 7927; i != 7928; i++)
    cout<<p.numSquares(i)<<",";
  cout<<endl;
}
