class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < nums.size(); ++i) {
            sorted[i] = make_pair(i, nums[i]);
        }
        SplitMerge(result, sorted, 0, n);
        return result;
    }
private:
    void SplitMerge(vector<int>& result, vector<pair<int, int>>& sorted, int start, int end) {
        if (end - start < 2) {
            return;
        }
        int middle = start + (end - start) / 2;
        SplitMerge(result, sorted, start, middle);
        SplitMerge(result, sorted, middle, end);
        vector<pair<int, int>> temp(end - start);
        int inversion = 0;
        for (int i = 0, index1 = start, index2 = middle; i < end - start; ++i) {
            if (index1 < middle && (index2 >= end || sorted[index1].second <= sorted[index2].second)) {
                temp[i] = sorted[index1];
                result[sorted[index1].first] += inversion;
                ++index1;
            } else {
                temp[i] = sorted[index2];
                ++index2;
                ++inversion;
            }
        }
        move(temp.begin(), temp.end(), sorted.begin() + start);
    }
};