/* 355. Design Twitter */
#include<vector>
#include<unordered_map>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() {
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    post_vec[userId].push_back(tweetId);
    posts.push_back(tweetId);
    posts_map[tweetId] = posts.size()-1;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> res1;
    set<int> res;
    int count = 0;
    for(set<int>::iterator it = follow_map[userId].begin();
        it != follow_map[userId].end(); it++){
      for(int i = post_vec[*it].size()-1; i != -1; i--){
        res.insert(posts_map[post_vec[*it][i]]);
        count++;
        if(count == 10){
          break;
        }
      }
      count = 0;
    }
    count = 0;
    for(int i=post_vec[userId].size()-1; i != -1; i--){
      res.insert(posts_map[post_vec[userId][i]]);
      count++;
      if(count == 10)
        break;
    }
    count = 0;
    for(set<int>::reverse_iterator rit = res.rbegin();
        rit != res.rend(); rit++){
      count++;
      res1.push_back(posts[*rit]);
      if(count == 10)
        break;
    }
    return res1;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    follow_map[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    follow_map[followerId].erase(followeeId);
  }
private:
  unordered_map<int,set<int> > follow_map;
  unordered_map<int,vector<int> > post_vec;
  vector<int> posts;
  unordered_map<int,int> posts_map;
};

int main()
{
  Twitter obj;
  vector<int> res;
  obj.postTweet(1, 5);
  obj.postTweet(1, 3);
  obj.postTweet(1, 101);
  obj.postTweet(1, 13);
  obj.postTweet(1, 10);
  obj.postTweet(1, 2);
  obj.postTweet(1, 94);
  obj.postTweet(1, 505);
  obj.postTweet(1, 333);
  res = obj.getNewsFeed(1);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<", ";
  /*
  cout<<endl;
  obj.follow(1, 2);
  obj.postTweet(2,6);
  res = obj.getNewsFeed(1);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<", ";
  cout<<endl;
  obj.unfollow(1,2);
  res = obj.getNewsFeed(1);
  for(int i = 0; i != res.size(); i++)
    cout<<res[i]<<", ";
  cout<<endl;
  */
  return 1;
}
