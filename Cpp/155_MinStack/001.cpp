class MinStack {
private:
    stack<int> st;
    stack<int> minValues;
public:
    void push(int x) {
        //这里必须是x <= minValues.top()而不是x < minValues.top()
        if (minValues.empty() || x <= minValues.top()) {
            minValues.push(x);
        }
        st.push(x);
    }

    void pop() {
        if (st.top() == minValues.top()) {
            minValues.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minValues.top();
    }
};