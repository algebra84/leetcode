/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
  static int maxProfit(vector<int>& prices) {
    vector<int> min;
    vector<int> profit;
    vector<int> maxb;
    vector<int> profitb;
    int result = 0;
    int N = prices.size();
    if(N < 2)
      return 0;
    min.push_back(prices[0]);
    maxb.push_back(prices[N-1]);
    profit.push_back(0);
    profitb.push_back(0);
    for(int i = 1; i != N; i++)
      min.push_back((prices[i]<min[i-1])?prices[i]:min[i-1]);
    for(int i = 1; i != N; i++)
      if(prices[i] > prices[i-1])
        profit.push_back((prices[i] - min[i-1])>profit[i-1]?(prices[i]-min[i-1]):profit[i-1]);
      else
        profit.push_back(profit[i-1]);

    for(int i = N-2; i != -1; i--)
      maxb.push_back((prices[i]>maxb[N-i-2])?prices[i]:maxb[N-2-i]);
    for(int i = N-2; i != -1; i--)
      if(prices[i] < prices[i+1])
        profitb.push_back((maxb[N-i-2] - prices[i])>profitb[N-i-2]?(maxb[N-i-2]-prices[i]):profitb[N-i-2]);
      else
        profitb.push_back(profitb[N-i-2]);

    for(int i = 0; i != N ; i++)
      result=(profit[i] + profitb[N-1-i])>result?(profit[i] + profitb[N-1-i]):result;
    return result;
  }
};

int main()
{
  int a[]={2,1,4,5,2,9,7};
  vector<int> prices(a,a+7);
  cout<<Solution::maxProfit(prices)<<endl;
  return 1;
}
