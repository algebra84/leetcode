/* 146. LRU Cache */
#include<list>
#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
  class TreeNode{
  public:
    int val;
    TreeNode* next;
    TreeNode* pre;
    TreeNode(int i){
      val = i;
      next = NULL;
      pre = NULL;
    }
  };

  LRUCache(int capacity) {
    size = 0;
    capa = capacity;
    phead = new TreeNode(0);
    pend = new TreeNode(0);
    phead->next = pend;
    pend->pre = phead;
  }
  int get(int key) {
    if(mmap1.count(key) > 0){
      TreeNode* tmp = mmap[key];
      tmp->pre->next = tmp->next;
      tmp->next->pre = tmp->pre;
      pend->pre->next = tmp;
      tmp->pre = pend->pre;
      tmp->next = pend;
      pend->pre = tmp;
      return mmap1[key];
    }
    else
      return -1;
  }

  void put(int key, int value) {
    if(mmap1.count(key) == 0){
      TreeNode* tmp = new TreeNode(key);
      tmp->pre = pend->pre;
      tmp->next = pend;
      pend->pre->next = tmp;
      pend->pre = tmp;
      mmap1[key] = value;
      mmap[key] = tmp;
      if(size == capa){
        TreeNode* tmp = phead->next;
        tmp->next->pre = phead;
        phead->next = tmp->next;
        mmap.erase(tmp->val);
        mmap1.erase(tmp->val);
        delete tmp;
      }
      else
        size++;
    }
    else{
      mmap1[key]=value;
      TreeNode* tmp = mmap[key];
      tmp->pre->next = tmp->next;
      tmp->next->pre = tmp->pre;
      pend->pre->next = tmp;
      tmp->pre = pend->pre;
      tmp->next = pend;
      pend->pre = tmp;
    }
  }

  ~LRUCache(){
    TreeNode* p = phead;
    while(p != NULL){
      TreeNode* tmp = p;
      p=p->next;
      delete tmp;
    }
  }
private:
  list<int> data;
  int size,capa;
  TreeNode* phead,*pend;
  unordered_map<int,TreeNode*> mmap;
  unordered_map<int,int> mmap1;
};


int main()
{
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout<<cache.get(1)<<endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout<<cache.get(2)<<endl;       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cout<<cache.get(1)<<endl;       // returns -1 (not found)
  cout<<cache.get(3)<<endl;       // returns 3
  cout<<cache.get(4)<<endl;       // returns 4

}

