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
    int minMeetingRooms(vector<Interval>& intervals) {
        //这个做法有一个好处是如果要求先加上start再减去end
        //可以把start的值设成-1,end的值设成1
        //这样sort时候就会把相同时间点的start point放到前面
        //end point放到后面
        //比如[[7,10],[9,10],[10,30]]就会返回3
        vector<pair<int, int>> changes;
        for (Interval& interval : intervals) {
            changes.emplace_back(interval.start, 1);
            changes.emplace_back(interval.end, -1);
        }
        int rooms = 0;
        int maxRooms = 0;
        sort(changes.begin(), changes.end());
        for (pair<int, int>& change : changes) {
            rooms += change.second;
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};