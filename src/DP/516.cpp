/* 516. Longest Palindromic Subsequence */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int dp(string& s,vector<vector<int> > &sq, int start, int end){
  if(sq[start][end] != -1)
    return sq[start][end];
  if(start > end)
    return 0;
  if(start+1 == end){
    if(s[start] == s[end])
      sq[start][end] = 2;
    else
      sq[start][end] = 1;
    return sq[start][end];
  }
  if(s[start] == s[end])
    sq[start][end] = 2+dp(s,sq,start+1,end-1);
  else
    sq[start][end] = max(dp(s,sq,start,end-1),dp(s,sq,start+1,end));
  return sq[start][end];
}

int longestPalindromeSubseq(string s){
  int size = s.size();
  vector<vector<int> > square(size,vector<int>(size,-1));
  for(int i = 0; i != size; i++)
    square[i][i] = 1;
  return dp(s,square,0,size-1);
}

int main()
{
  string s("bbbab");
  cout<<longestPalindromeSubseq(s)<<endl;
  return 1;
}
