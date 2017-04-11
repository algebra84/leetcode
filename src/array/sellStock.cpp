/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

  Example 1:
Input: [7, 1, 5, 3, 6, 4]
  Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
  Example 2:
Input: [7, 6, 4, 3, 1]
  Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  static int maxProfit(vector<int>& prices) {
    int N = prices.size();
    int profits = 0;
    for(int i = 0; i != N; i++){
      if(i > 0 && prices[i] == prices[i-1])
        continue;
      if(i < N-1 && prices[i] > prices[i+1])
        continue;
      for(int j = i+1; j!= N; j++)
        if(prices[j] - prices[i] > profits)
          profits = prices[j] - prices[i];
    }
    return profits;
  }
};

int main()
{
  int a[]={7, 1, 5, 3, 6, 4};
  vector<int> prices(a,a+6);
  cout<<Solution::maxProfit(prices)<<endl;
}
