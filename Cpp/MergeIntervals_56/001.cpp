/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct comp {
    bool operator()(const Interval& lhs, const Interval& rhs) {
        return lhs.start < rhs.start;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            return vector<Interval>();
        }
        sort(intervals.begin(), intervals.end(), comp());
        Interval newInterval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (newInterval.end >= intervals[i].start) {
                newInterval.end = max(intervals[i].end, newInterval.end);
            } else {
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
