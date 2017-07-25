/* 592. Fraction Addition and Subtraction */

#include<string>
#include<iostream>
using namespace std;
int gcd(int a,int b){
  if(b == 0)
    return a;
  return gcd(b, a%b);

}
string fractionAddition(string expression) {
  string curr_up,curr_down;
  int total_up = 0,total_down = 1;
  bool positive = true;
  bool up=true;
  int tmp_up,tmp_down,g,neg;
  expression+='+';
  for(auto c : expression){
    switch(c){
    case '-':
    case '+':
      if(curr_up.empty()){
        positive = (c=='-'?false:true);
        break;
      }
      tmp_up = 0;
      tmp_down = total_down*stoi(curr_down);
      if(positive)
        tmp_up = total_up*stoi(curr_down)+total_down*stoi(curr_up);
      else
        tmp_up = total_up*stoi(curr_down)-total_down*stoi(curr_up);
      positive = (c=='-'?false:true);
      neg = 1;
      if(tmp_up < 0){
        neg = -1;
        tmp_up *= -1;
      }
      g = gcd(tmp_up,tmp_down);
      total_up = tmp_up/g*neg;
      total_down = tmp_down/g;
      curr_up.clear();
      curr_down.clear();
      up = true;
      break;
    case '/':
      up = false;
      break;
    default:
      if(up)
        curr_up+=c;
      else
        curr_down+=c;
      break;
    }
  }
  return to_string(total_up)+'/'+to_string(total_down);

}

int main()
{
  cout<<fractionAddition("-1/2+1/2")<<endl;
  return 1;
}
