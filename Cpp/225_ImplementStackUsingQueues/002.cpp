class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q2.push(x);
        if (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        top();
        q2.pop();
    }
    
    // Get the top element.
    int top() {
        if (q2.empty()) {
            for (int i = 0; i < q1.size() - 1; ++i) {
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q1.pop();
        }
        return q2.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;//only store the last elment
};
