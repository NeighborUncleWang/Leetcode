class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int pre = INT_MIN, c1 = 0, c2 = 0, c3 = 0, cnt = 0;
        int p1 = 0, p2 = 0, p3 = 0, n = nums.size(), cur = 0;
        for (int i = 0; i < n; cur = pre, c1 = p1, c2 = p2, c3 = p3) {
            for (cur = nums[i], cnt = 0; i < size && nums[i] == cur; ++i) {
                if (cur != pre + 1) {
                    if (p1 != 0 || p2 != 0) return false;
                    c1 = cnt;
                    c2 = 0;
                    c3 = 0;
                } else {
                    if (cnt < p1 + p2) {
                        return false;
                    }
                    c1 = max(0, cnt - (p1 + p2 + p3));
                    c2 = p1;
                    c3 = p2 + min(p3, cnt - (p1 + p2));
                }
            }
        }
        return p1 == 0 && p2 == 0;
    }
};
