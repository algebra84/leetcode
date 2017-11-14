#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int> > combinationSum2(vector<int>& candidates, int target){
  vector<vector<vector<int> > > result(target+1);
  vector<int> result_num(target+1,0);
  for(int i = 0; i != candidates.size(); i++){
    int num = candidates[i];
    result_num[num]++;
  }

  int top_k = 0;
  for(int i = 1; i != target+1; i++)
    for(int j = 0; j != result_num[i];j++){
      top_k = min(target - i,top_k);
      for(int k = top_k; k != -1; k--){
        if(k == 0){
          if(j == 0)
            result[i].push_back(vector<int> (1,i));
          continue;
        }
        for(int m = 0; m != result[k].size(); m++){
          vector<int> cand(result[k][m]);
          cand.push_back(i);
          result[k+i].push_back(cand);
        }
      }
      top_k += i;

    }
  return result[target];
}

int main()
{
  int a[]={10, 1, 2, 7, 6, 1, 5};
  vector<int> num(a,a+7);
  vector<vector<int> > result = combinationSum2(num,8);
  for(int i = 0; i != result.size(); i++){
    for(int j = 0; j != result[i].size(); j++)
      cout<<result[i][j]<<",";
    cout<<endl;
  }
}
