#include<vector>
#include<iostream>
using namespace std;
void merge(vector<int> *a, int first,int mid, int last){
  vector<int> tmp;
  int i=first, j=mid+1;
  while(i<=mid || j<=last){
    if(i>mid && j<=last){
      tmp.push_back((*a)[j]);
      j++;
    }
    else if(i<=mid && j > last){
      tmp.push_back((*a)[i]);
      i++;
    }
    else{
      if((*a)[i] < (*a)[j]){
        tmp.push_back((*a)[i]);
        i++;
      }
      else{
        tmp.push_back((*a)[j]);
        j++;
      }
    }
  }

  for(int i = 0; i != tmp.size(); i++)
    (*a)[first+i] = tmp[i];
}
void mergeSort(vector<int> *a, int first, int last){
  int small,large;

  if(first == last)
    return;

  if(first < last){
    int mid = (first + last)/2;
    mergeSort(a, first, mid);
    mergeSort(a, mid+1, last);
    merge(a,first, mid, last);
  }
}
int main()
{
  int a[]={10,9,8,7,6,5,4,3,2,1};
  vector<int> array(a,a+10);
  mergeSort(&array, 0, 9);
  for(int i = 0; i != array.size(); i++)
    cout<<array[i]<<endl;
}
