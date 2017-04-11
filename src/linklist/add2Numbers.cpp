/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

                                    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
                                    Output: 7 -> 0 -> 8
*/

#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
  static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head;
    ListNode* tmp, *prev = NULL;
    int low = 0,high = 0,sum = 0;
    while(l1 || l2){
      if(l1 && !(l2)){
        sum = l1->val + high;
        l1 = l1->next;
      }
      else if(!(l1) && l2){
        sum = l2->val + high;
        l2 = l2->next;
      }
      else{
        sum = l1->val + l2->val + high;
        l1 = l1->next;
        l2 = l2->next;
      }

      low = sum%10;
      high = sum/10;
      tmp = new ListNode(low);
      if(prev){
        prev->next = tmp;
        prev = tmp;
      }
      else{
        head = tmp;
        prev = tmp;
      }
    }

    if(high){
      tmp = new ListNode(high);
      prev->next = tmp;
    }

    return head;

  }
};

int main()
{
  ListNode a1(2),a2(4),a3(5),b1(5),b2(6),b3(5);
  a1.next = &a2;
  a2.next = &a3;
  b1.next = &b2;
  b2.next = &b3;
  ListNode *r = Solution::addTwoNumbers(&a3, &b3);
  for(; r != NULL; r = r->next)
    cout<<r->val<<endl;
}
