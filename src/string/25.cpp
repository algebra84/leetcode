/* 25. Reverse Nodes in k-Group */
#include<stack>
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tmp=head;
    ListNode* phead=new ListNode(-1);
    ListNode* ptmp = phead;
    stack<ListNode*> ss;
    int count=0;
    while(tmp != NULL){
      ss.push(tmp);
      count++;
      tmp=tmp->next;
      if(count == k){
        while(ss.size()){
          ptmp->next = ss.top();
          ss.pop();
          ptmp=ptmp->next;
        }
        count = 0;
      }
    }
    while(count > 1){
      ss.pop();
      count--;
    }
    if(count == 1)
      ptmp->next=ss.top();
    else
      ptmp->next=NULL;
    return phead->next;
  }
};
