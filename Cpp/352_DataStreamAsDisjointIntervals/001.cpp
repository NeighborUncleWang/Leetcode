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
private:
    struct comp{
        bool operator()(Interval a, Interval b) { return a.start < b.start; }
    };
    set<Interval, comp> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = intervals.lower_bound(Interval(val, val));
        if (it != intervals.begin() && (--it)->end + 1 < val) ++it;
        int start = val, end = val;
        while (it != intervals.end() && it->end + 1 >= val && it->start - 1 <= val) {
            start = min(it->start, start);
            end = max(it->end, end);
            it = intervals.erase(it);
        }
        intervals.emplace_hint(it, start, end);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(intervals.begin(), intervals.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */