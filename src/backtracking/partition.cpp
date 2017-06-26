/* 131. Palindrome Partitioning */
#include<vector>
#include<string>
#include<iostream>
using namespace std;

bool palindrome(vector<char>& s){
  int i=0,j=s.size()-1;
  while(i<=j){
    if(s[i] != s[j])
      break;
    i++;
    j--;
  }
  if(i < j)
    return false;
  return true;
}
void partition_1(vector<vector<string> >& res,
                 vector<string>& cand,
                 string& s,int start,int index,
                 vector<char>& cur)
{
  cur.push_back(s[index]);
  if(index == s.size()-1){
    if(palindrome(cur)){
      cand.push_back(s.substr(start,index-start+1));
      res.push_back(cand);
      cand.pop_back();
    }
    return;
  }
  if(palindrome(cur)){
    cand.push_back(s.substr(start,index-start+1));
    vector<char> tmp;
    partition_1(res,cand,s,index+1,index+1,tmp);
    cand.pop_back();
  }
  partition_1(res,cand,s,start,index+1,cur);
}
vector<vector<string> > partition(string s){
  vector<string> cand;
  vector<vector<string> > res;
  vector<char> cur;
  if(!s.size())
    return res;
  partition_1(res,cand,s,0,0,cur);
  return res;
}

int main()
{
  string test = "ababbabb";
  vector<vector<string> > res = partition(test);
  for(int i = 0; i != res.size(); i++){
    cout<<"[";
    for(int j = 0; j != res[i].size(); j++)
      cout<<res[i][j]<<",";
    cout<<"]"<<endl;
  }
  return 1;
}
