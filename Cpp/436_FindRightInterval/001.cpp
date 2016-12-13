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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> starts;
        for (int i = 0; i < intervals.size(); ++i) {
            starts[intervals[i].start] = i;
        }
        vector<int> result;
        for (auto interval : intervals) {
            auto iter = starts.lower_bound(interval.end);
            if (iter != starts.end()) {
                result.push_back(iter->second);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};