class Twitter {
   public:
    unordered_map<int, vector<pair<int, int>>>
        tweets;                               // {userID , [{TweetID1,time} , TweetID2 ,....]}
    unordered_map<int, vector<int>> friends;  //{userID1 , userID2} user 1 follows user 2
    int time = 0;
    Twitter() {}

    void postTweet(int userId, int tweetId) { tweets[userId].push_back({tweetId, time++}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> users = friends[userId];
        users.push_back(userId);

        priority_queue<pair<int, int>> recents;

        for (int uId : users) {
            for (auto [twId, tm] : tweets[uId]) {
                recents.push({tm, twId});
            }
        }

        vector<int> page;

        int g = 10;

        while (g && !recents.empty()) {
            page.push_back(recents.top().second);
            recents.pop();
            g--;
        }
        return page;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        if (find(friends[followerId].begin(), friends[followerId].end(), followeeId) ==
            friends[followerId].end()) {
            friends[followerId].push_back(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        auto& v = friends[followerId];
        auto it = find(v.begin(), v.end(), followeeId);
        if (it != v.end()) v.erase(it);
    }
};
