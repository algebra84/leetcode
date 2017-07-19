#include<iostream>
using namespace std;

class MedianFinder {
public:
  class TreeNode{
  public:
    TreeNode* next;
    TreeNode* pre;
    int val;
    TreeNode(int i): val(i),next(NULL),pre(NULL){}
  };
  /** initialize your data structure here. */
  MedianFinder() {
    phead = new TreeNode(0);
    pend = new TreeNode(0);
    phead->next = pend;
    pend->pre = phead;
    pmed = NULL;
    size = 0;
  }
    
  void addNum(int num) {
    TreeNode* tmp = new TreeNode(num);
    if(size == 0){
      pmed = tmp;
      phead->next = tmp;
      pend->pre = tmp;
      tmp->next = pend;
      tmp->pre = phead;
    }
    else{
      TreeNode* p = pmed;
      if(p->val <= num){
        while(p != pend && p->val <= num)
          p = p->next;
        p->pre->next = tmp;
        tmp->pre = p->pre;
        p->pre = tmp;
        tmp->next = p;
        if(size%2==1)
          pmed = pmed->next;
      }
      else{
        while(p != phead && p->val > num)
          p=p->pre;
        p->next->pre = tmp;
        tmp->next = p->next;
        p->next = tmp;
        tmp->pre = p;
        if(size%2==0)
          pmed = pmed->pre;
      }
    }
    size++;
  }
    
  double findMedian() {
    if(size == 0)
      return 0;
    if(size%2==1)
      return (double)pmed->val;
    else
      return (double)(pmed->val+pmed->pre->val)/2.0;
  }

  ~MedianFinder() {
    while(phead){
      TreeNode* p = phead;
      phead = phead->next;
      delete p;
    }
  }
private:
  TreeNode* phead;
  TreeNode* pend;
  TreeNode* pmed;
  int size;
};

int main()
{
  MedianFinder md;
  md.addNum(1);
  md.addNum(2);
  cout<<md.findMedian()<<endl;
  md.addNum(3);
  cout<<md.findMedian()<<endl;
  return 1;
}
