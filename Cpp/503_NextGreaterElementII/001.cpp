class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            int num = nums[i % n];
            while (!st.empty() && num > nums[st.top()]) {
                res[st.top()] = num;
                st.pop();
            }
            //和Next Greater Element I不同的是这题stack存的是index
            //因为nums里有duplicates
            if (i < n) st.push(i);
        }
        return res;
    }
};