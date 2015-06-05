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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool newIntervalInserted = false;
        for (auto it : intervals) {
            if (newIntervalInserted) {
                result.push_back(it);
            } else if (it.end < newInterval.start) {
                result.push_back(it);
            } else if (it.start > newInterval.end) {
                result.push_back(newInterval);
                result.push_back(it);
                newIntervalInserted = true;
            } else {
                newInterval.start = min(it.start, newInterval.start);
                newInterval.end = max(it.end, newInterval.end);
            }
        }
        if (newIntervalInserted == false) {
            result.push_back(newInterval);
        }
        return result;
    }
};
