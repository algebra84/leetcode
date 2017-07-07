/* 322. Coin Change */

#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int build_1(vector<int>& coins,int amount,
            unordered_map<int,int> &mmap){
  if(mmap.count(amount))
    return mmap[amount];
  if(amount < 0)
    return -1;
  if(amount == 0)
    return 0;
  int result = 1000000;
  int flag = false;
  for(int i = 0; i != coins.size(); i++){
    int res = build_1(coins,amount-coins[i],mmap);
    if(res != -1){
      result = min(result,res+1);
      flag = true;
    }
  }
  if(!flag)
    result = -1;
  mmap[amount] = result;
  return mmap[amount];
}
int coinChange(vector<int>& coins, int amount) {
  unordered_map<int,int> mmap;
  return build_1(coins,amount,mmap);
}

int main()
{
  int a[] = {186,419,83,408};
  vector<int> coins(a,a+4);
  cout<<coinChange(coins,6249)<<endl;
  return 1;
}
