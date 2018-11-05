/* 275. H-Index II */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int num = citations.size();
    int res = 0;
    if(num == 0)
      return res;
    int start = 0;
    int end = num-1;
    int lower = -1,upper = -1;
    int res_index = -1;
    while(start <= end){
      int mid = (start + end)/2;
      if(num - mid < citations[mid]){
        end = mid-1;
        upper = mid;
      }
      else if((num-mid >= citations[mid]
               && mid >= num - citations[mid])
              || (num-mid-1 >= citations[mid]
                  && mid+1 >= num-citations[mid]))
      {
        res = citations[mid];
        res_index = mid;
        start = mid+1;
      }
      else{
        start = mid+1;
        lower = mid;
      }
    }
    lower = lower>res_index?lower:res_index;
    if(upper == -1)
      upper = 0;
    int res1 = num-upper;
    res1 = res1 > num-lower?num-lower:res1;
    if(res1 >= citations[lower] && res1 <= citations[upper])
      res = res1;
    return res;
  }
};

int main(){
  int a[]={1,1,1,1,1,1};
  vector<int> citations(a,a+6);
  Solution s;
  cout<<s.hIndex(citations)<<endl;
  return 0;
}
