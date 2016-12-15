class Solution {
private:
    bool helper(vector<int>& stones, unordered_map<int, bool>& map, int index, int k) {
        int key = index | (k << 16);
        if (map.count(key) > 0) return map[key];
        for (int i = index + 1; i < stones.size(); ++i) {
            int gap = stones[i] - stones[index];
            if (gap < k - 1) {
                continue;
            } else if (gap > k + 1) {
                return map[key] = false;
            } else if (helper(stones, map, i, gap)) {
                return map[key] = true;
            }
        }
        //这里不能用map[key] = true
        //否则[0,1,3,6,7]case过不去
        return map[key] = (index == stones.size() - 1);
    }
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> map;
        return helper(stones, map, 0, 0);
    }
};