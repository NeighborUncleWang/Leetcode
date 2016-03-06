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
        auto iter = intervals.begin();
        vector<Interval> result;
        while (iter != intervals.end() && iter->end < newInterval.start) {
            result.push_back(*iter++);
        }
        while (iter != intervals.end() && iter->start <= newInterval.end) {
            newInterval.start = min(iter->start, newInterval.start);
            newInterval.end = max(iter->end, newInterval.end);
            ++iter;
        }
        result.push_back(move(newInterval));
        while (iter != intervals.end()) {
            result.push_back(*iter++);
        }
        return result;
    }
};