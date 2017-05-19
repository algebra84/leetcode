/*57. Insert Interval
  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

  You may assume that the intervals were initially sorted according to their start times.

  Example 1:
  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

  Example 2:
  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;

//  Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  map<int,int> mmap;
  vector<Interval> res;
  intervals.push_back(newInterval);
  int N = intervals.size();
  if(N == 0)
    return res;
  map<int,int>::iterator mit;
  for(int i = 0; i != N; i++){
    if(mmap.count(intervals[i].start)
       && mmap[intervals[i].start] > intervals[i].end)
      ;
    else
      mmap[intervals[i].start] = intervals[i].end;
    if(!mmap.count(intervals[i].end))
      mmap[intervals[i].end] = intervals[i].end;
  }
  
  bool flag = false;
  int lower;
  int upper;
  for(mit = mmap.begin(); mit != mmap.end(); mit++){
    if(!flag){
      lower = mit->first;
      upper = mit->second;
      flag = true;
    }
    if(mit->first > upper){
      res.push_back(Interval(lower, upper));
      lower = mit->first;
      upper = mit->second;
    }
    else if(mit->first <= upper && mit->second > upper)
      upper = mit->second;
  }
  res.push_back(Interval(lower,upper));
  return res;
}

int main()
{
  Interval a1(1,3),a2(6,9),a3(2,5);
  vector<Interval> in;
  in.push_back(a1);
  in.push_back(a2);
  vector<Interval> res = insert(in,a3);
  for(int i = 0;i != res.size(); i++)
    cout<<"["<<res[i].start<<","<<res[i].end<<"]"<<endl;
}
