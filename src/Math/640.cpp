/* 640. Solve the Equation */
#include<string>
#include<vector>
#include<iostream>
using namespace std;
string solveEquation(string equation){
  vector<vector<int> > record(2,vector<int>(2,0));
  equation+='=';
  string x_val,int_val;
  int index1 = 0;
  bool positive = true;
  for(auto c:equation){
    switch(c){
    case 'x':
      x_val+='x';
      break;
    case '+':
    case '-':
    case '=':
      if(positive){
        if(x_val == "x")
          record[index1][0]+=int_val.empty()?1:stoi(int_val);
        else
          record[index1][1]+=int_val.empty()?0:stoi(int_val);
      }
      else{
        if(x_val == "x")
          record[index1][0]-=int_val.empty()?1:stoi(int_val);
        else
          record[index1][1]-=int_val.empty()?0:stoi(int_val);
      }
      x_val="";
      int_val="";
      if(c == '+')
        positive = true;
      else if(c == '-')
        positive = false;
      else{
        positive = true;
        index1 = 1;
      }
      break;
    default:
      int_val+=c;
      break;
    }
  }
  int x = record[0][0]-record[1][0];
  int b = record[1][1]-record[0][1];
  if(x==0 && b == 0)
    return "Infinite solutions";
  if(x==0 && b != 0)
    return "No solution";

  return "x="+to_string(b/x);
}
int main()
{
  cout<<solveEquation("-x=-1")<<endl;
  return 1;
}
