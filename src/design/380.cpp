/* 380. Insert Delete GetRandom O(1) */
#include<vector>
#include<unordered_map>
using namespace std;
class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if(mmap.count(val) > 0)
      return false;
    nums.push_back(val);
    mmap[val]=nums.size()-1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if(mmap.count(val) == 0)
      return false;
    nums[mmap[val]] = nums.back();
    mmap[nums.back()] = mmap[val];
    mmap.erase(val);
    nums.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums[rand()%nums.size()];
  }
private:
  unordered_map<int,int> mmap;
  vector<int> nums;
};
