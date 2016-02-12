/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &lhs, Interval &rhs) {
            return lhs.start < rhs.start;
        });
        vector<Interval> result;
        int n = intervals.size();
        if (n == 0) {
            return result;
        }
        Interval newInterval = intervals[0];
        for (int i = 1; i <= n; ++i) {
            if (i < n && intervals[i].start <= newInterval.end) {
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                result.push_back(newInterval);
                if (i < n) {
                    newInterval = intervals[i];
                }
            }
        }
        return result;
    }
};