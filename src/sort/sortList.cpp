/*148. Sort List
  Sort a linked list in O(n log n) time using constant space complexity.

  Subscribe to see which companies asked this question.
*/

#define NULL nullptr
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
  static ListNode* sortList(ListNode* head) {
    int num = 0;
    ListNode* p = head;
    ListNode* res;
    ListNode* first = head;
    ListNode* second = head;
    ListNode* first_after;
    ListNode* second_after;
    //count number of List
    while(p != NULL){
      p = p->next;
      num++;
    }
    if(num == 0 || num == 1)
      return head;
    //set second as the (num/2)th Listnode
    for(int i = 0; i != num/2 - 1; i++)
      second = second->next;
    p = second->next;
    second->next = NULL;
    second = p;
    first_after = sortList(first);
    second_after = sortList(second);

    res = new ListNode(0);
    p = res;
    //merge sort
    while(first_after != NULL || second_after != NULL){
      if(first_after == NULL){
        p->next = second_after;
        break;
      }
      if(second_after == NULL){
        p->next = first_after;
        break;
      }
      if(first_after->val < second_after->val){
        p->next = first_after;
        p = p->next;
        first_after = first_after->next;
      }
      else{
        p->next = second_after;
        p = p->next;
        second_after = second_after->next;
      }
    }
    p = res->next;
    delete res;
    return p;
  }
};

int main()
{
  ListNode* p1 = new ListNode(8);
  ListNode* p2 = new ListNode(7);
  ListNode* p3 = new ListNode(6);
  ListNode* p4 = new ListNode(5);
  ListNode* p5 = new ListNode(4);
  ListNode* p6 = new ListNode(3);
  ListNode* p7 = new ListNode(2);
  ListNode* p8 = new ListNode(1);
  p1->next = p2;
  p2->next = NULL;
  p3->next = p4;
  p4->next = p5;
  p5->next = p6;
  p6->next = p7;
  p7->next = p8;
  ListNode* res = Solution::sortList(p1);
  while(res != NULL){
    cout<<res->val<<endl;
    res = res->next;
  }
  return 1;
}
