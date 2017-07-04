/* 464. Can I Win */
#include<vector>
#include<iostream>
#include<set>
using namespace std;
bool win_1(set<int> &mset, int total){

}

bool canIWin(int maxChoosableInteger, int desiredTotal){
  set<int> mset;
  for(int i = 0; i != maxChoosableInteger; i++)
    mset.insert(i+1);
  return win_1(mset,desiredTotal);
}
