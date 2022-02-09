#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>

using namespace std;

class Twitter {

public:
    Twitter() {
        recent_max = 10;
        time = 0;
        user.clear();
        tweet_time.clear();
    }

    void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end()) {
            init(userId);
        }

        if (user[userId].tweet.size() == recent_max) {
            user[userId].tweet.pop_back();
        }

        user[userId].tweet.push_front(tweetId);
        tweet_time[tweetId] = ++time;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        ans.clear();

        for (auto it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it) {
            ans.emplace_back(*it);
        }

        for (auto followeeId: user[userId].followee) {
            if (followeeId == userId) continue;
            vector<int> res;
            res.clear();
            auto it = user[followeeId].tweet.begin();
            int i = 0;
            while (i < ans.size() && it != user[followeeId].tweet.end()) {
                if (tweet_time[*it] > tweet_time[ans[i]]) {
                    res.emplace_back(*it);
                    ++it;
                } else {
                    res.emplace_back(ans[i]);
                    ++i;
                }
                if (res.size() == recent_max) break;
            }

            for (; i < ans.size() && res.size() < recent_max; ++i) {
                res.emplace_back(ans[i]);
            }

            for (; it != user[followeeId].tweet.end() && res.size() < recent_max; ++it) {
                res.emplace_back(*it);
            }
            ans.assign(res.begin(), res.end());
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (user.find(followerId) == user.end()) {
            init(followerId);
        }

        if (user.find(followeeId) == user.end()) {
            init(followeeId);
        }

        user[followerId].followee.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
    }

    void init(int userId) {
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }

private:
    struct Node {
        unordered_set<int> followee;
        list<int> tweet;
    };

    int recent_max;
    int time;
    unordered_map<int, Node> user;
    unordered_map<int, int> tweet_time;

};