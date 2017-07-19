/* 155. Min Stack */
// all in O(1) time
#include<stack>
#include<iostream>
using namespace std;
class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {

  }

  void push(int x) {
    data.push(x);
    if(Min_data.empty() || x<=getMin())
      Min_data.push(x);
  }

  void pop() {
    if(data.top() == getMin())
      Min_data.pop();
    data.pop();
  }

  int top() {
    return data.top();
  }

  int getMin() {
    return Min_data.top();
  }
private:
  stack<int> data;
  stack<int> Min_data;
};
