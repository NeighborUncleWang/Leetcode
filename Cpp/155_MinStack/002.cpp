class MinStack {
private:
    stack<int> st;
    stack<int> minValues;
public:
    void push(int x) {
        if (minValues.empty() || x <= minValues.top()) {
            minValues.push(x);
        }
        st.push(x);
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (top == minValues.top()) {
            minValues.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minValues.top();
    }
};