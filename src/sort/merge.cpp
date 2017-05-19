/*56. Merge Intervals
  Given a collection of intervals, merge all overlapping intervals.

  For example,
  Given [1,3],[2,6],[8,10],[15,18],
  return [1,6],[8,10],[15,18].*/


#include<vector>
#include<iostream>
#include<map>
using namespace std;
// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {
  map<int,int> mmap;
  vector<Interval> res;
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
  Interval a1(1,2),a2(3,6);
  vector<Interval> in;
  in.push_back(a1);
  in.push_back(a2);
  vector<Interval> res = merge(in);
  for(int i = 0;i != res.size(); i++)
    cout<<"["<<res[i].start<<","<<res[i].end<<"]"<<endl;
}
