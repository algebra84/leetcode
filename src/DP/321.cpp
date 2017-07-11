/* 321. Create Maximum Number*/

#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
#if 0
string build_1(vector<int> &nums1, int index1,
               vector<int>& nums2, int index2,
               int k, unordered_map<string,string> &mmap){
  string result;
  if(k == 0)
    return result;
  int size1 = nums1.size();
  int size2 = nums2.size();
  string key = to_string(index1)+" "+to_string(index2)+" "+to_string(k);
  if(mmap.count(key))
    return mmap[key];

  int max1[2]={-1,-1};
  int max2[2]={-1,-1};

  int end1 = (k-size2+index2 <= 0)?size1:(size1-(k-size2+index2)+1);
  int end2 = (k-size1+index1 <= 0)?size2:(size2-(k-size1+index1)+1);

  for(int i = index1; i != end1; i++)
    if(max1[1] < nums1[i]){
      max1[1] = nums1[i];
      max1[0] = i;
    }
  for(int i = index2; i != end2; i++)
    if(max2[1] < nums2[i]){
      max2[1] = nums2[i];
      max2[0] = i;
    }
  if(max1[1] < max2[1]){
    result = to_string(max2[1]) + build_1(nums1,index1,nums2,max2[0]+1,k-1,mmap);
  }
  else if(max1[1] > max2[1]){
    result = to_string(max1[1]) + build_1(nums1,max1[0]+1,nums2,index2,k-1,mmap);
  }
  else{
    string result1 = to_string(max2[1]) + build_1(nums1,index1,nums2,max2[0]+1,k-1,mmap);
    string result2 = to_string(max1[1]) + build_1(nums1,max1[0]+1,nums2,index2,k-1,mmap);
    result = (result1.compare(result2) > 0)?result1:result2;
  }
  mmap[key] = result;
  return result;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
  unordered_map<string,string> mmap;
  vector<int> res;
  if(k > (nums1.size() + nums2.size()))
    return res;
  string result = build_1(nums1,0,nums2,0,k,mmap);
  for(int i = 0; i != result.size(); i++)
    res.push_back(result[i]-'0');
  return res;
}
#endif
#if 1
vector<int> maxVector(vector<int> nums, int k) {
  while (nums.size() > k) {
    int i = 0, n = nums.size();
    for (; i < n - 1; ++i) {
      if (nums[i] < nums[i + 1]) {
        nums.erase(nums.begin() + i);
        break;
      }
    }
    if (i == n - 1) nums.erase(nums.begin() + i);
  }

  return nums;
}

bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
  while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
    ++i;
    ++j;
  }
  if (j == nums2.size()) return true;
  if (i < nums1.size() && nums1[i] > nums2[j]) return true;
  return false;
}

vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
  vector<int> res(k, 0);
  for (int i = 0, j = 0, r = 0; r < k; ++r) {
    res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
  }

  return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
  int m = nums1.size(), n = nums2.size();
  vector<int> res(k, 0);

  for (int i = max(0, k - n); i <= min(k, m); ++i) {
    auto v1 = maxVector(nums1, i);
    auto v2 = maxVector(nums2, k - i);
    auto tmp = merge(v1, v2, k);
    if (compare(tmp, 0, res, 0)) res = tmp;
  }

  return res;
}
#endif
int main()
{

  int a[]={3, 4, 6, 5};
  int b[]={9, 1, 2, 5, 8, 3};
  vector<int> n1(a,a+4);
  vector<int> n2(b,b+6);
  vector<int> result = maxNumber(n1,n2,5);
  for(int i = 0; i != result.size(); i++)
    cout<<result[i]<<",";
  cout<<endl;
  return 1;
}
