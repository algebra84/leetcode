/* 593. Valid Square */
#include<vector>
using namespace std;
int distance(vector<int>& p1,vector<int>& p2){
  return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
}
//p2-p1;p4-p3
bool cross(vector<int>&p1, vector<int>&p2,vector<int>&p3,vector<int>&p4){
  return ((p2[0]-p1[0])*(p4[0]-p3[0])+(p2[1]-p1[1])*(p4[1]-p3[1])) == 0;
}
bool same(vector<int>&p1, vector<int>& p2){
  return (p1[0]==p2[0])&&(p1[1]==p2[1]);
}

bool validSquare(vector<int>& p1, vector<int>& p2,
                 vector<int>& p3, vector<int>& p4){
  if(same(p1,p2) || same(p1,p3) || same(p1,p4)
     || same(p2,p3) || same(p2,p4) || same(p3,p4))
    return false;
  if(distance(p1,p2)==distance(p1,p3)){
    if(cross(p1,p2,p1,p3) && cross(p4,p2,p4,p3)
       && distance(p4,p2)==distance(p4,p3))
      return true;
    return false;
  }
  else if(distance(p1,p2)==distance(p1,p4)){
    if(cross(p1,p2,p1,p4) && cross(p3,p2,p3,p4)
       && distance(p3,p2)==distance(p3,p4))
      return true;
    return false;

  }
  else if(distance(p1,p3)==distance(p1,p4)){
    if(cross(p1,p3,p1,p4) && cross(p2,p3,p2,p4)
       && distance(p2,p3) == distance(p2,p4))
      return true;
    return false;
  }
  else
    return false;
}
