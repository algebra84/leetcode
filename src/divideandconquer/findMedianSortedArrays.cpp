/*4. Median of Two Sorted Arrays
  There are two sorted arrays nums1 and nums2 of size m and n respectively.

  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

  Example 1:
  nums1 = [1, 3]
  nums2 = [2]

  The median is 2.0
  Example 2:
  nums1 = [1, 2]
  nums2 = [3, 4]

  The median is (2 + 3)/2 = 2.5*/

#include<vector>
#include<iostream>
using namespace std;
int findK(vector<int>& nums1, vector<int>& nums2,int start1, int start2, int size1, int size2, int K){
  if(size1 == 0)
    return nums2[start2+K-1];
  else if(size2 == 0)
    return nums1[start1+K-1];
  if(nums1[start1 + size1/2] >= nums2[start2 + size2/2]){
    if((size1/2+size2/2+1)>=K)
      return findK(nums1,nums2,start1,start2,size1/2,size2,K);
    else
      return findK(nums1,nums2,start1,start2+size2/2+1,size1,size2-size2/2-1,K-size2/2-1);
  }
  else
    return findK(nums2,nums1,start2,start1,size2,size1,K);
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
  double res = 0.0;
  int num1 = nums1.size();
  int num2 = nums2.size();
  if((num1 + num2)%2)
    res = findK(nums1,nums2,0,0,num1,num2,(num1+num2+1)/2);
  else
    res = (findK(nums1,nums2,0,0,num1,num2,(num1+num2)/2) + findK(nums1,nums2,0,0,num1,num2,(num1+num2)/2+1))*0.5;
  return res;
}

int main()
{
  int a[]={1,3,5,7,9};
  int b[]={2,4,6,8,10};
  vector<int> nums1(a,a+3);
  vector<int> nums2(b,b+3);
  cout<<findMedianSortedArrays(nums1,nums2)<<endl;
}
