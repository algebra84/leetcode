/* Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

  Example:
  Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  void count(int* pcount, vector<int> &mvec, int n){
    if(n == 0){
      (*pcount)++;
      return;
    }
    for(int i = 0; i != 10; i++){
      if(i == 0 && mvec.size() == 0){
        count(pcount, mvec, n-1);
        continue;
      }
      int dup = 0;
      for(int j = 0; j != mvec.size(); j++)
        if(i == mvec[j]){
          dup = 1;
          break;
        }
      if(!dup){
        mvec.push_back(i);
        count(pcount, mvec, n-1);
        mvec.pop_back();
      }
    }
  }
  int countNumbersWithUniqueDigits(int n) {
    vector<int> mvec;
    int mcount = 0;
    if(n == 0)
      return 1;
    count(&mcount, mvec, n);
    return mcount;
  }
};

int main()
{
  Solution s;
  for(int i = 1; i != 16; i++)
    cout<<s.countNumbersWithUniqueDigits(i)<<endl;
}
