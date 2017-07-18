/* 232. Implement Queue using Stacks */

#include<stack>
#include<iostream>
using namespace std;
class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    if(data.empty())
      peek_val = x;
    data.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int tmp_int;
    stack<int> tmp_stack;
    if(data.size() == 0)
      return 0;
    while(data.size()){
      tmp_int = data.top();
      data.pop();
      tmp_stack.push(tmp_int);
    }
    int res = tmp_stack.top();
    tmp_stack.pop();
    if(tmp_stack.size())
      peek_val = tmp_stack.top();
    else
      peek_val = 0;
    while(tmp_stack.size()){
      tmp_int = tmp_stack.top();
      tmp_stack.pop();
      data.push(tmp_int);
    }
    return res;
  }

  /** Get the front element. */
  int peek() {
    return peek_val;
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return data.empty();
  }
private:
  stack<int> data;
  int peek_val;
};

int main()
{
  MyQueue m;
  m.push(2);
  cout<<m.pop()<<endl;
  cout<<m.peek()<<endl;
  cout<<m.empty()<<endl;
  return 1;
}
