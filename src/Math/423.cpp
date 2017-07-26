/* 423. Reconstruct Original Digits from English */
#include<string>
#include<vector>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<iostream>
using namespace std;
bool valid_number(int num,vector<unordered_map<char,int> > &book){
  bool res = false;
  switch(num){
  case 0:
  case 4:
  case 5:
    if(book[num].size() == 4)
      res = true;
    break;
  case 1:
  case 2:
  case 6:
    if(book[num].size() == 3)
      res = true;
    break;
  case 3:
  case 7:
    if(book[num].size() == 4 && book[num]['e'] >= 2)
      res = true;
    break;
  case 8:
    if(book[num].size() == 5)
      res = true;
    break;
  case 9:
    if(book[num].size() == 3 && book[num]['n'] >= 2)
      res = true;
    break;
  default:
    break;
  }
  return res;
}
string originalDigits(string s) {
  multiset<int> res;
  string result;
  vector<unordered_set<int> > dict(26);
  vector<unordered_map<char,int> > book(10);
  string dictstr[10]={"zero","one","two","three","four",
                      "five","six","seven","eight","nine"};
  for(int i = 0; i != 10; i++)
    for(int j = 0; j != dictstr[i].size(); j++)
      dict[dictstr[i][j]-'a'].insert(i);
  for(auto c:s){
    unordered_set<int>::iterator it;
    int valid_num = -1;
    for(it = dict[c-'a'].begin(); it != dict[c-'a'].end();it++){
      book[*it][c]++;
      if(valid_number(*it,book))
        valid_num = *it;
    }
    if(valid_num != -1){
      res.insert(valid_num);
      for(auto c1:dictstr[valid_num])
        for(it = dict[c1-'a'].begin(); it != dict[c1-'a'].end(); it++){
          if(book[*it][c1] == 1)
            book[*it].erase(c1);
          else
            book[*it][c1]--;
        }
    }
  }
  for(multiset<int>::iterator it = res.begin(); it != res.end(); it++)
    result+=to_string(*it);
  return result;
}

int main()
{
  cout<<originalDigits("zenorine")<<endl;
  return 1;
}
