/* 93. Restore IP Addresses */
#include<string>
#include<vector>
#include<iostream>
using namespace std;
bool valid_ip(string s){
  if(s.size() > 3 || s.size() == 0)
    return false;
  if(s.size() > 1 && s[0] == '0')
    return false;
  int ip = stoi(s);
  if(ip >= 0 && ip <= 255)
    return true;
  return false;
}
void restore_1(string &s, int index,vector<string> &cand,vector<string> &res){
  if(index == s.size())
    return;
  if(cand.size() == 3){
    string ipstr = s.substr(index,s.size()-index);
    if(valid_ip(ipstr)){
      string result;
      cand.push_back(ipstr);
      for(auto ts:cand)
        result= result + ts +".";
      result.pop_back();
      res.push_back(result);
      cand.pop_back();
    }
    return;
  }
  int i = 0;
  while(index + i < s.size()
        && i != 3){
    i++;
    string ipstr = s.substr(index,i);
    if(valid_ip(ipstr)){
      cand.push_back(ipstr);
      restore_1(s,index+i,cand,res);
      cand.pop_back();
    }
    else
      break;
  }
  return;
}

vector<string> restoreIpAddresses(string s){
  vector<string> res,cand;
  if(s.size() < 4)
    return res;
  restore_1(s,0,cand,res);
  return res;
}

int main()
{
  string s("25525511135");
  vector<string> result=restoreIpAddresses(s);
  for(auto ts:result)
    cout<<ts<<endl;
  return 1;
}
