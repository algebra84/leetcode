/*315. Count of Smaller Numbers After Self
  You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

  Example:

  Given nums = [5, 2, 6, 1]

  To the right of 5 there are 2 smaller elements (2 and 1).
  To the right of 2 there is only 1 smaller element (1).
  To the right of 6 there is 1 smaller element (1).
  To the right of 1 there is 0 smaller element.
  Return the array [2, 1, 1, 0].*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;
vector<int> result;
struct ListNode{
  int val;
  int index;
  ListNode* next;
  ListNode(int x, int id): val(x), index(id),next(NULL){}
};
ListNode* mergeSort(ListNode* head,int num){
  if (num == 0 || num == 1)
    return head;
  int low = num/2;
  int high = num - num/2;
  ListNode* mid = head;
  ListNode* prev = NULL;
  for(int i = 0; i != low; i++){
    prev = mid;
    mid = mid->next;
  }
  prev->next = NULL;
  ListNode* lowlist = mergeSort(head,low);
  ListNode* highlist = mergeSort(mid, high);
  ListNode* res = new ListNode(0,-1);
  mid = res;
  int j = 0;
  while(lowlist != NULL || highlist != NULL){
    if(lowlist == NULL){
      mid->next = highlist;
      break;
    }
    if(highlist == NULL){
      mid->next = lowlist;
      mid = mid->next;
      result[lowlist->index] += (num - num/2);
      lowlist = lowlist->next;
      continue;
    }
    if(lowlist->val <= highlist->val){
      mid->next = lowlist;
      mid = mid->next;
      result[lowlist->index] += j;
      lowlist = lowlist->next;
    }
    else{
      mid->next = highlist;
      mid = mid->next;
      highlist = highlist->next;
      j++;
    }
  }
  mid = res->next;
  delete res;
  return mid;
}
vector<int> countSmaller(vector<int>& nums) {
  int N = nums.size();
  ListNode* head = new ListNode(-1,-1);
  ListNode* cur = head;
  for(int i = 0; i != N; i++){
    cur->next = new ListNode(nums[i],i);
    cur=cur->next;
    result.push_back(0);
  }
  cur = mergeSort(head->next,N);
  for(int i = 0; i != N; i++){
    ListNode* tmp= cur;
    cur = cur->next;
    delete tmp;
  }
  return result;
}

int main()
{
  int a[10000];
  vector<int> nums(a,a+10000);
  vector<int> res = countSmaller(nums);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<endl;
  return 1;
}
