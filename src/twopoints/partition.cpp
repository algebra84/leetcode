/* 86. Partition List
   Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

   You should preserve the original relative order of the nodes in each of the two partitions.

   For example,
   Given 1->4->3->2->5->2 and x = 3,
   return 1->2->2->4->3->5.

   Subscribe to see which companies asked this question.*/
#include<iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x){
  ListNode* ptmp,*pvalue = NULL,*ptmp_prev = NULL;
  ListNode* plesshead = new ListNode(0);
  ListNode* pless = plesshead;
  ListNode* pgreathead = new ListNode(0);
  ListNode* pgreat = pgreathead;
  while(head){
    if(head->val >= x){
      pgreat->next = head;
      pgreat = head;
      head = head->next;
      pgreat->next = NULL;
    }
    else{
      pless->next = head;
      pless = head;
      head = head->next;
      pless->next = NULL;
    }
  }

  if(plesshead->next == NULL)
    return pgreathead->next;
  else{
    pless->next = pgreathead->next;
    return plesshead->next;
  }

}

int main()
{
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(4);
  ListNode* p3 = new ListNode(3);
  ListNode* p4 = new ListNode(2);
  ListNode* p5 = new ListNode(5);
  ListNode* p6 = new ListNode(2);
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;
  p5->next = p6;
  ListNode* res = partition(p1,3);
  for(ListNode* tmp = res; tmp != NULL; tmp = tmp->next)
    cout<<tmp->val<<endl;
}
