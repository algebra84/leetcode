/*210. Course Schedule II
  There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;
vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites){
  vector<int> result;
  int N = prerequisites.size();
  if(0 == N){
    for(int i = 0; i != numCourses; i++){
      result.push_back(i);
    }
    return result;
  }
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
          return vector<int>();
      }
      if(!flag){
        mqueue.pop_back();
        result.push_back(p);
        visited[p] = 2;
      }
    }
  }
  return result;
}
int main()
{
  vector<pair<int, int> > tmp;
  tmp.push_back(make_pair(0,1));
  vector<int> result = findOrder(2,tmp);
  for(int i = 0; i != result.size(); i++)
    cout<<result[i]<<"<-";
  return 1;
}
