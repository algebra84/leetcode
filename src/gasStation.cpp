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
  vector<int> need(size, 0), avail(size, 0);
  for(int i = 0;i != size; i++){
    need[i] = cost[i] - gas[i];
  }

  for(int i = 0; i != size; i++){
    if(need[i] > 0)
      continue;
    int j = (i+size-1)%size;
    int sum = 0;
    while(j != i){
      sum += need[j];
      if(sum < 0)
        sum = 0;
      j = (j-1+size)%size;
    }
    if(sum+need[i] <= 0)
      return i;
  }
  return -1;
}

int main()
{
  int a[]={3,2,1};
  int b[]={1,2,3};
  vector<int> va(a,a+3), vb(b,b+3);
  cout<<canCompleteCircuit(vb,va)<<endl;
}
