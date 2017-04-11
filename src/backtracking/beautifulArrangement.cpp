/*Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

1.  The number at the ith position is divisible by i.
2.  i is divisible by the number at the ith position.
  Now given N, how many beautiful arrangements can you construct?

  Example 1:
  Input: 2
  Output: 2
  Explanation: 

  The first beautiful arrangement is [1, 2]:

  Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

  Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

  The second beautiful arrangement is [2, 1]:

  Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

  Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
  Note:
  N is a positive integer and will not exceed 15.
 */

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
  void countArrangement_1(int* pcount, int begin, int left, vector<int>* mvec){
    // one solution
    if(left == 1){
      for(int i = 1; i != begin+left; i++)
        if((*mvec)[i-1])
          continue;
        else{
          if(i % begin == 0 || begin % i == 0)
            *pcount = *pcount + 1;
          return;
        }
      return;
    }
    for(int i = 1; i != left + begin; i++){
      if((*mvec)[i-1])
        continue;
      if(i%begin == 0 || begin%i==0){
        (*mvec)[i-1]=begin;
        countArrangement_1(pcount, begin+1, left-1,mvec);
        (*mvec)[i-1]=0;
      }
    }
  }

  int countArrangement(int N) {
    vector<int> mvec(N, 0);
    int count = 0;
    if(N == 0)
      return 0;
    countArrangement_1(&count, 1, N, &mvec);
    return count;
  }
};


int main()
{
  Solution s;
  for(int i = 1; i != 16; i++)
    cout<<s.countArrangement(i)<<endl;

}
