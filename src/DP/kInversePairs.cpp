/* 629. K Inverse Pairs Array */

#include<vector>
#include<iostream>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
int kInversePairs(int n, int k){
  int mod = 1000000007;
  if(k > (n-1)*n/2)
    return 0;
  if(n < 2)
    return k==0;
  vector<vector<int> > dp;
  dp.push_back(vector<int> (1,0));
  for(int i = 2; i != n+1; i++)
    dp.push_back(vector<int>(MIN(i*(i-1)/2+1,k+1),0));
  dp[1][0]=1;
  dp[1][1]=1;
  for(int i = 2; i != n; i++)
    for(int j = 0; j != MIN(k+1,i*(i+1)/2+1); j++){
      if(j == 0)
        dp[i][j] = 1;
      else{
        if(j <= MIN(k,i*(i-1)/2))
          dp[i][j] = dp[i-1][j];
        dp[i][j] += dp[i][j-1];
        if((j-i-1)>=0)
          dp[i][j] -= dp[i-1][j-i-1];
        if(dp[i][j] < 0)
          dp[i][j] += mod;
        dp[i][j] %= mod;
      }
    }
  return dp[n-1][k];
}
int main()
{
  int n = 5;
  int sum = 0;
#if 0
  for(int i = 0; i != (n-1)*n/2+1;i++){
    int res = kInversePairs(n,i);
    sum += res;
    cout<<"n = "<<n<<"i = "<<i<<": "<<res<<endl;
  }
  cout<<"sum: "<<sum<<endl;
#endif
  int res = 1000000007;
  //  cout<<res*3<<endl;
  cout<<kInversePairs(1000,1000)<<endl;
  return 1;
}
