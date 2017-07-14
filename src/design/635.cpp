/* 635. Design Log Storage System */
//2017:01:01:23:59:59
#include<vector>
#include<map>
using namespace std;
class LogSystem {
public:
  map<string,int> mmap;
  LogSystem() {
  }

  void put(int id, string timestamp) {
    mmap[timestamp] = id;
  }

  vector<int> retrieve(string s, string e, string gra) {
    vector<int> res;
    map<string,int>::iterator begin;
    map<string,int>::iterator end;
    string begin_str;
    string end_str;
    int index;
    if(gra == "Year")
      index = 4;
    else if(gra == "Month")
      index = 7;
    else if(gra == "Day")
      index = 10;
    else if(gra == "Hour")
      index = 13;
    else if(gra == "Minute")
      index = 16;
    else
      index = 19;
    begin_str = s.substr(0,index);
    end_str = e.substr(0,index);
    if(end_str[index-1] <'9')
      end_str[index-1]+=1;
    else{
      end_str[index-2]+=1;
      end_str[index-1]='0';
    }
    begin = mmap.lower_bound(begin_str);
    end = mmap.lower_bound(end_str);
    for(map<string,int>::iterator it = begin; it != end; it++)
      res.push_back(it->second);
    return res;
  }
};
