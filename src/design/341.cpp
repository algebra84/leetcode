/* 341. Flatten Nested List Iterator*/
#include<vector>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    index = 0;
    for(int i = 0; i != nestedList.size(); i++)
      getNest(nestedList[i]);
  }

  void getNest(const NestedInteger& nestI){
    if(nestI.isInteger()){
      data.push_back(nestI.getInteger());
      return;
    }
    const vector<NestedInteger> nestl = nestI.getList();
    for(int i = 0; i != nestl.size(); i++)
      getNest(nestl[i]);
    return;
  }

  int next() {
    return data[index++];
  }

  bool hasNext() {
    return index < data.size();
  }
private:
  vector<int> data;
  int index;
};
