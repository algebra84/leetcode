/*207. Course Schedule

  There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

#include<iostream>
#include<utility>
#include<vector>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites){
  int N = prerequisites.size();
  if(0 == N)
    return true;
  vector<vector<int> > adjlist(numCourses, vector<int>(1,-1));
  for(int i = 0; i != N; i++)
    adjlist[prerequisites[i].first].push_back(prerequisites[i].second);
  vector<int> visited(numCourses, 0);
  vector<int> mqueue;
  for(int i = 0; i != numCourses; i++){
    if(visited[i] == 2)
      continue;
    mqueue.push_back(i);
    visited[i] = 1;
    while(mqueue.size()){
      int p = mqueue.back();
      bool flag = false;
      for(int k = 0; k != adjlist[p].size(); k++){
        if(adjlist[p][k] == -1)
          continue;
        if(visited[adjlist[p][k]] == 0){
          mqueue.push_back(adjlist[p][k]);
          visited[adjlist[p][k]] = 1;
          flag=true;
          break;
        }
        else if(visited[adjlist[p][k]] == 1)
          return false;
      }
      if(!flag){
        mqueue.pop_back();
        visited[p] = 2;
      }
    }
  }
  return true;
}

int main()
{
  vector<pair<int, int> > tmp;
  tmp.push_back(make_pair(0,1));
  cout<<canFinish(2,tmp)<<endl;
}
