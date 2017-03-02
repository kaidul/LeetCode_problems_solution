class Twitter {
    class User {
    public:
        vector<pair<int, int>> tweets;
        unordered_set<int> followeeIds;
    };
    class tweet {
    public:
        int userId;
        int tweetId;
        int indx;
        unsigned int _time;
        tweet() {}
        tweet(int a, int b, int c, unsigned int d): tweetId(a), userId(b), indx(c), _time(d) {
        }
        bool operator < (tweet const& other) const {
            return _time < other._time;
        }
    };
    unordered_map<int, User> users;
    unsigned int timestamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
        users = unordered_map<int, User>();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(userId < 0 or tweetId < 0) return;
        users[userId].tweets.push_back({tweetId, ++timestamp});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        priority_queue<tweet> recentTweets;
        
        if(!users[userId].tweets.empty()) {
           recentTweets.push(tweet(users[userId].tweets[(int)users[userId].tweets.size() - 1].first, userId, (int)users[userId].tweets.size() - 1, users[userId].tweets[(int)users[userId].tweets.size() - 1].second)); 
        }
        
        for(auto it = users[userId].followeeIds.begin(); it != users[userId].followeeIds.end(); ++it) {
            if(!users[*it].tweets.empty()) {
                recentTweets.push(tweet(users[*it].tweets[(int)users[*it].tweets.size() - 1].first, *it, (int)users[*it].tweets.size() - 1, users[*it].tweets[(int)users[*it].tweets.size() - 1].second));
            }
        }
        while((int)newsFeed.size() < 10 and !recentTweets.empty()) {
            newsFeed.push_back(recentTweets.top().tweetId);
            int id = recentTweets.top().userId;
            int indx = recentTweets.top().indx;
            recentTweets.pop();
            if(indx > 0) {
                recentTweets.push(tweet(users[id].tweets[indx - 1].first, id, indx - 1, users[id].tweets[indx - 1].second));
            }
        }
        
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(followerId < 0 or followeeId < 0) return;
        users[followerId].followeeIds.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(followerId < 0 or followeeId < 0) return;
        users[followerId].followeeIds.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */