class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto i : nums) {
            if (map.count(i) == 0) {
                ++map[i];
            } else {
                return true;
            }
        }
        return false;
    }
};
