/* 62. Unique Paths */

#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(int m, int n){
  vector<vector<int> > a(m,vector<int> (n));
  for(int i = 0; i != m; i++)
    for(int j = 0; j != n; j++){
      if(i == 0)
        a[i][j] = 1;
      else if(j == 0)
        a[i][j] = 1;
      else
        a[i][j] = a[i-1][j]+a[i][j-1];
    }
  return a[m-1][n-1];
}
int main()
{
  cout<<uniquePaths(3,7)<<endl;
  return 1;
}

