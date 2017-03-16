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
            //其实newInterval.start = min(iter->start, newInterval.start);只需要对这个while loop
            //里的第一个iter做，后面的其实不需要
            //后面的iter指向的interval只会更新newInterval.end
            //但是为了满足条件的iter单独写一个if statement代码会比较难看，所以就不那样写了
            newInterval.start = min(iter->start, newInterval.start);
            newInterval.end = max(iter->end, newInterval.end);
            ++iter;
        }
        result.push_back(move(newInterval));
        result.insert(result.end(), iter, intervals.end());
        return result;
    }
};