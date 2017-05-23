/*514. Freedom Trail
  https://leetcode.com/problems/freedom-trail/#/description
 */

#include<string>
using namespace std;
int findRotateSteps(string ring, string key){
  int size_k = key.size();
  if(size_k == 1){
    int res1,res2;
    for(int i = 0; i != ring.size();i++)
      if(ring[i] == key[0]){
        res1 = i;
        break;
      }
    for(int i = ring.size()-1; i != -1; i--)
      if(ring[i] == key[i]){
        res2 = ring.size()-1-i;
        break;
      }
    return res1>res2?(res2+1):(res1+1);
  }
}
