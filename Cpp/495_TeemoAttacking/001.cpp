class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size(), res = 0;
        if (n == 0) return 0;
        int start = timeSeries.front();
        for (int i = 1; i < n; ++i) {
            if (timeSeries[i] > timeSeries[i - 1] + duration) {
                res += timeSeries[i - 1] + duration - start;
                start = timeSeries[i];
            }
        }
        res += timeSeries.back() + duration - start;
        return res;
    }
};