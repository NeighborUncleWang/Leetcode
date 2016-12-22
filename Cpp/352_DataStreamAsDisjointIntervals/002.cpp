/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto comp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(intervals.begin(), intervals.end(), Interval(val, val), comp);
        if (it != intervals.begin() && (it - 1)->end + 1 >= val) {
            --it;
        }
        int start = val, end = val;
        while (it != intervals.end() && val + 1 >= it->start && val - 1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = intervals.erase(it);
        }
        intervals.emplace(it, start, end);
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */