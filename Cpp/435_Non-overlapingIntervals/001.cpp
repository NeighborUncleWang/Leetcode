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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.end < b.end;
        });
        int count = 0;
        int end = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start >= end) {
                ++count;
                end = intervals[i].end;
            }
        }
        return intervals.size() - count;
    }
};