class MinStack {
public:
    void push(int x) {
        //assume stack is not empty
        st.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        } else {
            if (x <= minStack.top()) {
                minStack.push(x);
            }
        }
    }

    void pop() {
        //assume stack is not empty
        int peek = st.top();
        if (peek == minStack.top()) {
            st.pop();
            minStack.pop();
        } else {
            st.pop();
        }
    }

    int top() {
        //assume stack is not empty
        return st.top();
    }

    int getMin() {
        //assume stack is not empty
        return minStack.top();
    }
private:
    stack<int> st;
    stack<int> minStack;
};
