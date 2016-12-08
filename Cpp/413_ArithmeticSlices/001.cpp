class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int current = 0, sum = 0;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                ++current;
                sum += current;
            } else {
                current = 0;
            }
        }
        return sum;
    }
};