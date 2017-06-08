/* 554. Brick Wall*/
#include<vector>
#include<iostream>
#include<map>
using namespace std;
int leastBricks(vector<vector<int> >& wall){
  map<int, int> mmap;
  for(int i = 0; i != wall.size(); i++){
    int sum = 0;
    for(int j = 0; j != wall[i].size(); j++){
      sum += wall[i][j];
      mmap[sum]++;
    }
  }
  int max = 0;
  int count = 0;
  for(map<int,int>::iterator it = mmap.begin(); it != mmap.end(); it++){
    if(it->second > max && count != mmap.size()-1)
      max = it->second;
    count++;
  }
  return wall.size() - max;
}

int main(){
  int a0[]={1};
  int a1[]={1};
  int a2[]={1};
  int a3[]={1};
  int a4[]={1};
  int a5[]={1};
  vector<int> level0(a0,a0+1);
  vector<int> level1(a1,a1+1);
  vector<int> level2(a2,a2+1);
  vector<int> level3(a3,a3+1);
  vector<int> level4(a4,a4+1);
  vector<int> level5(a5,a5+1);
  vector<vector<int> > wall;
  wall.push_back(level5);
  wall.push_back(level4);
  wall.push_back(level3);
  wall.push_back(level2);
  wall.push_back(level1);
  wall.push_back(level0);
  cout<<leastBricks(wall)<<endl;
}
