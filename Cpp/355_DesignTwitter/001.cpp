class Twitter {
private:
    int time = 0;
    struct Tweet {
        int tweet_id;
        int time_stamp;
        Tweet(int id, int time) {
            tweet_id = id;
            time_stamp = time;
        }
    };
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, deque<Tweet>> tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
    
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_front(tweetId, ++time);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        using value_type = pair<deque<Tweet>::iterator, deque<Tweet>::iterator>;
        auto comp = [](value_type left, value_type right) {
            return left.first->time_stamp < right.first->time_stamp;
        };
        priority_queue<value_type, vector<value_type>, decltype(comp)> heap(comp);
        for (int user : followees[userId]) {
            if (!tweets[user].empty()) {
                heap.emplace(tweets[user].begin(), tweets[user].end());
            }
        }
        if (!tweets[userId].empty()) {
            heap.emplace(tweets[userId].begin(), tweets[userId].end());
        }
        vector<int> result;
        for (int i = 0; i < 10 && !heap.empty(); ++i) {
            auto top = heap.top();
            heap.pop();
            result.push_back(top.first->tweet_id);
            ++top.first;
            if (top.first != top.second) {
                heap.emplace(top.first, top.second);
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
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