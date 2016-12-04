class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size();
        unordered_map<int, int> sum_map;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                ++sum_map[A[i] + B[j]];
            }
        }
        int result = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (sum_map.find(-(C[i] + D[j])) != sum_map.end()) {
                    result += sum_map[-(C[i] + D[j])];
                }
            }
        }
        return result;
    }
};