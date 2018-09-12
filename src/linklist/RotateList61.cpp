#include<stdio.h>
class ListNode;
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  static ListNode* rotateRight(ListNode* head, int k) {
    int num = 0;
    ListNode* piter = head;
    ListNode* pcut = NULL;
    ListNode* pend = NULL;
    while(piter){
      if(piter->next == NULL)
        pend = piter;
      piter = piter->next;
      num++;
    }
    if(num < 2)
      return head;
    k = k%num;
    if( k == 0)
      return head;
    piter = head;
    if(k == num - 1){
      piter = head->next;
      pend->next = head;
      head->next = NULL;
      return piter;
    }
    k = num -k -1;
    num = 0;
    while(piter){
      piter = piter->next;
      num++;
      if(num == k){
        pcut = piter;
        break;
      }
    }
    pend->next = head;
    piter = pcut->next;
    pcut->next = NULL;
    return piter;
  }
};


int main(){
  for(int i = 0; i != 10; i++){

    ListNode  p1(1),p2(2),p3(3),p4(4),p5(5);
    ListNode *tmp = &p1;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    printf("\n Rotated list %d:\n", i);
    ListNode* res = Solution::rotateRight(&p1, i);
    while(res){
      printf("%d, ",res->val);
      res=res->next;
    }
    printf("\n");
  }

  return 1;
}
