/*There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 */

#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int size = gas.size();
  if(size == 0)
    return -1;
  int tank = 0, start = 0, total = 0;
  for(int i = 0; i != size; i++){
    tank = tank + gas[i] - cost[i];
    if(tank < 0){
      total += tank;
      tank = 0;
      start = i+1;
    }
  }
  if(tank + total < 0)
    return -1;
  else
    return start;
}

int main()
{
  int a[]={3,2,1};
  int b[]={1,2,3};
  vector<int> va(a,a+3), vb(b,b+3);
  cout<<canCompleteCircuit(vb,va)<<endl;
}
