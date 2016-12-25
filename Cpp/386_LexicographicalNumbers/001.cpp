class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int current = 1;
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = current;
            if (current * 10 <= n) {
                current *= 10;
            } else {
                if (current == n) {
                    current /= 10;
                }
                ++current;
                while (current % 10 == 0) {
                    current /= 10;
                }
            }
        }
        return result;
    }
};