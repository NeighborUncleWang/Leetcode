class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = timeSeries.size() * duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            res -= max(0, timeSeries[i - 1] + duration - timeSeries[i]);
        }
        return res;
    }
};