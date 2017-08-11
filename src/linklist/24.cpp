/* 24. Swap Nodes in Pairs */
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* phead = head->next;
    ListNode* prev=head,*ptmp;
    if(head->next == NULL)
      return head;
    head->next = phead->next;
    phead->next = head;
    while(prev->next != NULL && prev->next->next != NULL){
      ptmp = prev->next;
      prev->next = ptmp->next;
      ptmp->next = prev->next->next;
      prev->next->next = ptmp;
      prev=ptmp;
    }
    return phead;
  }
};
