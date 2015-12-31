class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int lowBound = INT_MIN;
        for (int val : preorder) {
            if (val < lowBound) {
                return false;
            }
            while (!st.empty() && st.top() < val) {
                lowBound = st.top();
                st.pop();
            }
            st.push(val);
        }
        return true;
    }
};