class MyCalendarThree {
private:
    map<int, int> events;
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        ++events[start];
        --events[end];
        int cur = 0, res = 0;
        for (auto& it : events) {
            cur += it.second;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
