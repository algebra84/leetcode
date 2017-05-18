/*147. Insertion Sort List
  Sort a linked list using insertion sort.
*/

#include<iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  static ListNode* insertionSortList(ListNode* head) {
    ListNode* head_p = new ListNode(0);
    while(head){
      ListNode* next_head = head->next;
      ListNode* p = head_p->next;
      ListNode* prev = head_p;
      while(p){
        if(p->val >= head->val){
          prev->next = head;
          head->next = p;
          break;
        }
        prev = p;
        p = p->next;
      }
      if(!p){
        prev->next = head;
        head->next = NULL;
      }
      head = next_head;
    }
    return head_p->next;
  }
};

int main(){
  ListNode* p1 = new ListNode(8);
  ListNode* p2 = new ListNode(7);
  ListNode* p3 = new ListNode(6);
  ListNode* p4 = new ListNode(5);
  ListNode* p5 = new ListNode(4);
  ListNode* p6 = new ListNode(3);
  ListNode* p7 = new ListNode(2);
  ListNode* p8 = new ListNode(1);
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;
  p5->next = p6;
  p6->next = p7;
  p7->next = p8;
  ListNode* res = Solution::insertionSortList(p1);
  while(res != NULL){
    cout<<res->val<<endl;
    res = res->next;
  }
  return 1;
}
