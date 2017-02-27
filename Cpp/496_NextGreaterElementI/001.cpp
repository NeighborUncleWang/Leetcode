class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> map;
        stack<int> st;
        for (int num : nums) {
            while (!st.empty() && num > st.top()) {
                map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> res;
        for (int num : findNums) {
            res.push_back(map.find(num) == map.end() ? -1 : map[num]);
        }
        return res;
    }
};