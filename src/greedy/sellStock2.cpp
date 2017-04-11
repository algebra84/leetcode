/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  static int maxProfit(vector<int>& prices) {
    int N = prices.size();
    int profits = 0;
    if(N == 0)
      return 0;
    for(int i = 0; i != N - 1; i++){
      if(prices[i] < prices[i+1])
        profits+=(prices[i+1] - prices[i]);
    }
    return profits;
  }
};

int main()
{
  int a[]={7,1,6,4,5};
  vector<int> prices(a,a+5);
  cout<<Solution::maxProfit(prices)<<endl;
  return 0;
}
