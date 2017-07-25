/* 537. Complex Number Multiplication */
#include<iostream>
#include<string>
using namespace std;
string complexNumberMultiply(string a, string b) {
  int com[2][2]={{0,0},{0,0}};
  a+="+";
  b+="+";
  string curi,curc;
  bool flag = true;
  for(auto c:a){
    switch(c){
    case '+':
      if(curc.empty())
        com[0][0]+=stoi(curi);
      else
        com[0][1]=stoi(curi);
      curi.clear();
      curc.clear();
      break;
    case 'i':
      curc+='c';
      break;
    default:
      curi+=c;
    }
  }
  for(auto c:b){
    switch(c){
    case '+':
      if(curc.empty())
        com[1][0]+=stoi(curi);
      else
        com[1][1]=stoi(curi);
      curi.clear();
      curc.clear();
      break;
    case 'i':
      curc+='c';
      break;
    default:
      curi+=c;
    }
  }
  int r1,r2;
  r1=com[0][0]*com[1][0]-com[0][1]*com[1][1];
  r2=com[0][0]*com[1][1]+com[0][1]*com[1][0];
  return to_string(r1)+"+"+to_string(r2)+'i';
}
int main()
{
  cout<<complexNumberMultiply("1+-1i","1+-1i")<<endl;
  return 1;
}
