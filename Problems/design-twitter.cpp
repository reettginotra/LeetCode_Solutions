#include <bits/stdc++.h>
using namespace std;

class Twitter {
    int timer = 0;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for (auto &t : tweets[userId])
            pq.push(t);

        for (int u : followMap[userId])
            for (auto &t : tweets[u])
                pq.push(t);

        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
