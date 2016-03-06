class MinStack {
private:
    long long min;
    stack<long long> st;
public:
    void push(int x) {
        if (st.empty()) {
            st.push(0);
            min = x;
        } else {
            st.push(x - min);
            if (x < min) {
                min = x;
            }
        }
    }

    void pop() {
        long long diff = st.top();
        st.pop();
        if (diff < 0) {
            min -= diff;
        }
    }

    int top() {
        //如果st.top() < 0
        //表示st.top() update了min
        //所以直接return min
        if (st.top() < 0) {
            return min;
        } else {
            return min + st.top();
        }
    }

    int getMin() {
        return min;
    }
};