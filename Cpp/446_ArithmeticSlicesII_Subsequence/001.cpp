class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        int size = A.size();
        vector<unordered_map<int, int>> map(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)A[i] - A[j];
                if (diff < INT_MIN || diff > INT_MAX) continue;
                //这里写成这样防止而不是int count = map[j][diff];
                //是为了防止插入hash_table太多次
                int count = map[j].count(diff) ? map[j][diff] : 0;
                result += count;
                map[i][diff] += count + 1;
            }
        }
        return result;
    }
};