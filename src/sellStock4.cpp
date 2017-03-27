/*Say you have an array for which the ith element is the price of a given stock on day i.

  Design an algorithm to find the maximum profit. You may complete at most k transactions.

  Note:
  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include<vector>
#include<iostream>
#define INT_MIN -32767
#define max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;
class Solution {
public:
  static int maxProfit(int k, vector<int>& prices) {
    int N = prices.size();
    if(N < 2)
      return 0;
    if(k > N/2){
      int result = 0;
      for(int i = 1; i != N; i++)
        if(prices[i] > prices[i-1])
          result += (prices[i] - prices[i-1]);
      return result;
    }
    vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
    for(int i = 0; i != N; i++)
      for(int j = 1; j != k+1; j++){
        buy[j] = max(buy[j], sell[j-1] - prices[i]);
        sell[j] = max(sell[j], buy[j] + prices[i]);
      }
    return sell[k];
  }
};

int main()
{
  int a[]={1,3,5,2,9,7,6,3};
  vector<int> prices(a,a+8);
  cout<<Solution::maxProfit(2, prices)<<endl;
  return 1;
}
