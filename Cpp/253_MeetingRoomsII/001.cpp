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
        map<int, int> changes;
        for (Interval interval : intervals) {
            ++changes[interval.start];
            --changes[interval.end];
        }
        int maxRooms = 0;
        int rooms = 0;
        for (auto change : changes) {
            rooms += change.second;
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};