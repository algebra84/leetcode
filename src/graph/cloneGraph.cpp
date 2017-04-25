/* 133. Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
Subscribe to see which companies asked this question.*/

#include<vector>
#include<map>
#include<iostream>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
  if(node == NULL)
    return NULL;
  vector<UndirectedGraphNode*> mqu_src;
  vector<UndirectedGraphNode*> mqu_dst;
  map<int,int> visited;
  map<int,UndirectedGraphNode*> mmap;
  mqu_src.push_back(node);
  UndirectedGraphNode* result=new UndirectedGraphNode(node->label);
  mqu_dst.push_back(result);
  visited[node->label] = 1;
  mmap[node->label] = result;
  while(mqu_src.size()){
    UndirectedGraphNode* src=mqu_src.back();
    UndirectedGraphNode* dst=mqu_dst.back();
    int flag = false;
    for(int i = visited[src->label] - 1; i != (src->neighbors).size(); i++){
      visited[src->label]++;
      if(visited[src->neighbors[i]->label] == 0){
        UndirectedGraphNode* child = new UndirectedGraphNode(src->neighbors[i]->label);
        mmap[src->neighbors[i]->label] = child;
        dst->neighbors.push_back(child);
        mqu_src.push_back(src->neighbors[i]);
        mqu_dst.push_back(child);
        flag = true;
        visited[src->neighbors[i]->label] = 1;
        break;
      }
      dst->neighbors.push_back(mmap[src->neighbors[i]->label]);
    }
    if(!flag){
      mqu_src.pop_back();
      mqu_dst.pop_back();
      visited[src->label] = 2;
    }
  }
  return result;
}
