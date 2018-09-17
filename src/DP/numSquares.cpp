/* 279. Perfect Squares */
#include<cmath>
#include<iostream>
#include<cstdbool>
#include<map>

using namespace std;
class Solution {
public:
  map<int,int> dpmap;
  int numSquares(int n) {
    if(dpmap.count(n) > 0)
      return dpmap[n];
    if(isSquare(n)){
      dpmap.insert(std::pair<int, int>(n, 1));
      return 1;
    }
    int res = n; 
    for(int i = 1; i != n/2 + 1; i++){
      int low = numSquares(i);
      int high = numSquares(n-i);
      if(low + high < n)
        res = low + high;
    }
    dpmap.insert(std::pair<int, int>(n,res));
    return res;
  }
  bool isSquare(int n){
    int r = sqrt(n);
    return r*r == n;
  }
  Solution();
};

int main()
{
  class p;
  cout<<p.numSquares(13)<<endl;
}
