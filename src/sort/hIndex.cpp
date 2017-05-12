/*274. H-Index
  Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

  According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

  For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

  Note: If there are several possible values for h, the maximum one is taken as the h-index.*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int hIndex(vector<int>& citations){
  sort(citations.begin(), citations.end());
  int N = citations.size();
  int result = 0;
  for(int i = 0; i != N; i++)
    if(citations[i] >= N-i
      //       && (i == 0 || citations[i] > citations[i-1])
       && result < N-i)
      result = N-i;
  return result;
}

int main()
{
  int a[]={3,0,6,1,5};
  vector<int> ci(a,a+5);
  cout<<hIndex(ci)<<endl;
  return 1;
}
