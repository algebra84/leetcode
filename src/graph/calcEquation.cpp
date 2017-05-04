/*399. Evaluate Division
  Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

  Example:
  Given a / b = 2.0, b / c = 3.0. 
  queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
  return [6.0, 0.5, -1.0, 1.0, -1.0 ].

  The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

  According to the example above:

  equations = [ ["a", "b"], ["b", "c"] ],
  values = [2.0, 3.0],
  queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
  The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.*/

#include<vector>
#include<utility>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<iostream>
using namespace std;

vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries){
  vector<double> result;
  unordered_map<string,unordered_map<string,double> > m;
  for(int i = 0; i != values.size(); i++){
    m[equations[i].first][equations[i].second] = values[i];
    m[equations[i].first][equations[i].first] = 1.0;
    if(values[i] != 0){
      m[equations[i].second][equations[i].first] = 1.0/values[i];
      m[equations[i].second][equations[i].second] = 1.0;
    }
  }
  for(auto i:queries){
    if(m.count(i.first) == 0){
      result.push_back(-1.0);
      continue;
    }
    bool flag = false;
    queue<string> qu;
    unordered_set<string> visited;
    qu.push(i.first);
    while(qu.size()){
      string p = qu.front();
      qu.pop();
      visited.insert(p);
      if(m[p].count(i.second) > 0){
        result.push_back(m[i.first][p] * m[p][i.second]);
        flag = true;
        break;
      }
      for(auto j:m[p]){
        if(visited.count(j.first) > 0)
          continue;
        qu.push(j.first);
        m[i.first][j.first] = m[i.first][p]*m[p][j.first];
      }
    }
    if(!flag)
      result.push_back(-1.0);
  }
  return result;
}

int main(){
  vector<pair<string, string> > src;
  vector<double> val;
  vector<pair<string, string> > que;
  src.push_back(make_pair("a","b"));
  val.push_back(2.0);
  src.push_back(make_pair("b","c"));
  val.push_back(3.0);
  que.push_back(make_pair("a","c"));
  que.push_back(make_pair("b","a"));
  que.push_back(make_pair("a","e"));
  que.push_back(make_pair("a","a"));
  que.push_back(make_pair("x","x"));
  vector<double> result = calcEquation(src,val,que);
  for(int i = 0; i != result.size(); i++){
    cout<<result[i]<<endl;
  }
  return 1;
 }
