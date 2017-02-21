class HitCounter {
private:
    vector<int> hits = vector<int>(300, 0);
    vector<int> times = vector<int>(300, 0);
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        //如果times[index] ！= timestamp
        //证明times[index] 里存的是 timestamp - 300 * k的结果
        //肯定已经在300秒之前，所以可以放心覆盖掉
        if (times[index] == timestamp) {
            ++hits[index];
        } else {
            times[index] = timestamp;
            hits[index] = 1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int result = 0;
        for (int i = 0; i < 300; ++i) {
            if (timestamp - times[i] < 300) {
                result += hits[i];
            }
        }
        return result;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */