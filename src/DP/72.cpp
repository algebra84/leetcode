/* 72. Edit Distance */
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
#if 1
int build_1(string &word1,int index1, string &word2,int index2, vector<vector<int> > &mmap){
  if(index2 == word2.size())
    return word1.size()-index1;
  if(index1 == word1.size())
    return word2.size()-index2;
  if(mmap[index1][index2] != -1)
    return mmap[index1][index2];

  // Insert
  int s1 = 1+build_1(word1,index1,word2,index2+1,mmap);
  // Delete
  int s2 = 1+build_1(word1,index1+1,word2,index2,mmap);
  // Replace
  int s3 = (word1[index1]!=word2[index2])+build_1(word1,index1+1,word2,index2+1,mmap);
  int result = s1>s2?s2:s1;
  result = result>s3?s3:result;
  mmap[index1][index2] = result;
  return result;
}
#endif
int minDistance(string word1, string word2) {
  int size1 = word1.size();
  int size2 = word2.size();
  if(size1 == 0 || size2 == 0)
    return size1+size2;
  vector<vector<int> >  a(size1,vector<int> (size2,-1));
  int result = build_1(word1,0,word2,0,a);
  return result;
}

int main()
{
  // cout<<minDistance("bba","ab")<<endl;
  cout<<minDistance("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef","bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg")<<endl;
  return 1;
}
