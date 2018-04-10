class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, left_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            left_max = max(arr[i], left_max);
            if (left_max == i) {
                ++res;
            }
        }
        return res;
    }
};
