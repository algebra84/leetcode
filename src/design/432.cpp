/* 432. All O`one Data Structure */

#include<string>
#include<list>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class AllOne {
public:
  /** Initialize your data structure here. */
  AllOne() {

  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    if(data.count(key) == 0){
      if(buck.size() == 0 || data[*(buck.front().begin())] > 1){
        unordered_set<string> tmp;
        tmp.insert(key);
        buck.push_front(tmp);
      }
      else 
        buck.front().insert(key);
      data_map[key]=buck.begin();
      data[key]++;
    }
    else{
      list<unordered_set<string> >::iterator it= data_map[key];
      it->erase(key);
      it++;
      if(it == buck.end() || data[*(it->begin())] != data[key]+1){
        unordered_set<string> tmp;
        tmp.insert(key);
        buck.insert(it,tmp);
        it--;
        data_map[key] = it;
      }
      else{
        it->insert(key);
        data_map[key] =it;
      }
      it--;
      if(it->empty())
        buck.erase(it);
      data[key]++;
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    if(data.count(key) == 0)
      return;
    if(data[key] == 1){
      data.erase(key);
      data_map[key]->erase(key);
      if(data_map[key]->empty())
        buck.erase(data_map[key]);
      return;
    }
    list<unordered_set<string> >::iterator it= data_map[key],pre;
    it->erase(key);
    pre = --it;
    it++;
    if(it == buck.begin() || data[*((pre)->begin())] != data[key]-1){
      unordered_set<string> tmp;
      tmp.insert(key);
      buck.insert(it,tmp);
      it--;
      data_map[key] = it;
      it++;
    }
    else{
      pre->insert(key);
      data_map[key] = pre;
    }
    if(it->empty())
      buck.erase(it);
    data[key]--;
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    if(buck.size() == 0)
      return "";
    return *(buck.back().begin());
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    if(buck.size() == 0)
      return "";
    return *(buck.front().begin());
  }
private:
  unordered_map<string,int> data;
  unordered_map<string,list<unordered_set<string> >::iterator > data_map;
  list<unordered_set<string> > buck;
};

int main()
{
  AllOne obj;
  obj.inc("hello");
  obj.inc("goodbye");
  obj.inc("hello");
  obj.inc("hello");
  cout<<obj.getMaxKey()<<endl;
  obj.inc("leet");
  obj.inc("code");
  obj.inc("leet");
  obj.dec("hello");
  obj.inc("leet");
  obj.inc("code");
  obj.inc("code");
  cout<<obj.getMaxKey()<<endl;
  return 1;
}
