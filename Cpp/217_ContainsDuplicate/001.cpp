class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num : nums) {
            //insert returns pair<iterator, bool>
            //bool indicates whether insertion took place or not
            if (hashSet.insert(num).second == false) {
                return true;
            }
        }
        return false;
    }
};