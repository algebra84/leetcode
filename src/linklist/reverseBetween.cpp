#include<iostream>
using namespace std;
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  static ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *phead = NULL;
    ListNode *pend = NULL;
    ListNode *ptmp = NULL;
    ListNode *head_plus = new ListNode(-1);
    head_plus->next = head;
    ListNode *iter = head_plus;
    if(m == n)
      return head;
    int i = 1;
    while(iter){
      if(m == i)
        phead = iter;
      if(n + 1 == i){
        pend = iter->next;
        iter->next = NULL;
        break;
      }
      iter=iter->next;
      i++;
    }

    iter = phead->next;
    while(iter){
      ptmp = iter->next;
      iter->next = pend;
      pend = iter;
      iter = ptmp;
    }
    phead->next = pend;
    return head_plus->next;
  }

};

int main(){
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(2);
  ListNode* p3 = new ListNode(3);
  ListNode* p4 = new ListNode(4);
  ListNode* p5 = new ListNode(5);
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;

  ListNode* res = Solution::reverseBetween(p1, 1,1);
  while(res){
    cout<<res->val<<",";
    res = res->next;
  }
  cout<<endl;
}
