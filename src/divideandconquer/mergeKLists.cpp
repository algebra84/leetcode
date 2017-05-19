/*23. Merge k Sorted Lists
  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/

#include<vector>
#include<iostream>
using namespace std;
//  Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwolists(ListNode* l1, ListNode* l2){
  if(l1 == NULL)
    return l2;
  if(l2 == NULL)
    return l1;
  if(l1->val < l2->val){
    l1->next = mergeTwolists(l1->next,l2);
    return l1;
  }
  else{
    l2->next = mergeTwolists(l1,l2->next);
    return l2;
  }
}
ListNode* mergeKLists(vector<ListNode*>& lists){
  if(lists.size() == 0)
    return NULL;
  while(lists.size() > 1){
    lists.push_back(mergeTwolists(lists[0],lists[1]));
    lists.erase(lists.begin());
    lists.erase(lists.begin());
  }
  return lists[0];
}

int main(){
  ListNode* p1 = new ListNode(0);
  ListNode* p2 = new ListNode(2);
  ListNode* p3 = new ListNode(5);
  vector<ListNode*> lists;
  lists.push_back(p1);
  lists.push_back(p2);
  lists.push_back(p3);
  ListNode* res = mergeKLists(lists);
  while(res){
    cout<<res->val<<endl;
    res=res->next;
  }
  return 1;
}
