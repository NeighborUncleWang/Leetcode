/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        return (st.top().first++)->getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().first == st.top().second) {
                st.pop();
            } else {
                auto current = st.top().first;
                if (current->isInteger()) {
                    return true;
                } else {
                    ++st.top().first;
                    st.emplace(current->getList().begin(), current->getList().end());
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */