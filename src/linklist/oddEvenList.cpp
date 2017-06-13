/* 328. Odd Even Linked List*/
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head){
  if(head == NULL)
    return head;
  int id = 0;
  ListNode* phead = head;
  ListNode* pend = head->next;
  while(pend && pend->next){
    ListNode* tmp = phead->next;
    phead->next = pend->next;
    pend->next = pend->next->next;
    pend = pend->next;
    phead->next->next = tmp;
    phead = phead->next;
  }

  return head;
}

int main()
{
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(2);
  ListNode* p3 = new ListNode(3);
  ListNode* p4 = new ListNode(4);
  ListNode* p5 = new ListNode(5);
  ListNode* p6 = new ListNode(6);
  ListNode* p7 = new ListNode(7);
  ListNode* p8 = new ListNode(8);
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;
  p5->next = p6;
  p6->next = p7;
  //  p7->next = p8;
  ListNode* res = oddEvenList(p1);
  while(res){
    cout<<res->val<<endl;
    res = res->next;
  }
  return 1;
}
