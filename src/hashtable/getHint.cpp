/* 299. Bulls and Cows */
#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
string getHint(string secret, string guess) {
  map<int,int> mmap;
  int bull=0,cows=0;
  int i = 0;
  int n1 = secret.size(), n2 = guess.size();
  while(i != n1 || i != n2){
    if(i == n1 && mmap[guess[i]] > 0){
      cows++;
      i++;
      mmap[guess[i]]--;
      continue;
    }
    if(i == n2 && mmap[secret[i]] < 0){
      cows++;
      i++;
      mmap[secret[i]]++;
      continue;
    }
    if(guess[i] == secret[i])
      bull++;
    else{
      if(mmap[guess[i]] > 0)
        cows++;
      if(mmap[secret[i]] < 0)
        cows++;
      mmap[guess[i]]--;
      mmap[secret[i]]++;
    }
    i++;
  }
  string bullstr = to_string(bull);
  string cowstr= to_string(cows);
  string res = bullstr+"A"+cowstr+"B";
  return res;
}

int main()
{
  string s="1123";
  string g="0111";
  cout<<getHint(s,g)<<endl;
}
