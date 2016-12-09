class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, current = 0, size = A.size();
        for (int i = 0; i < size; ++i) {
            current += i * A[i];
            sum += A[i];
        }
        int result = current;
        for (int i = size - 1; i > 0; --i) {
            current = current - size * A[i] + sum;
            result = max(result, current);
        }
        return result;
    }
};