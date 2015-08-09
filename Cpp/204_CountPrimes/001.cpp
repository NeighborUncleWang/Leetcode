class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int count = 0;
        //这题因为是找primes less than n, 所以用i * i < n
        //如果是找no more than n(包含n), 应该用i * i <= n, 否则当n为9就会出错
        //如果是包含n都要找到包含sqrt(n)为止
        //题解建议用i * i instead of sqrt(n)来避免多次调用sqrt省时间，但是 i * i有可能造成overflow啊
        //如果造成overflow会不会造成最后 i > n? 比如 n = INT_MAX - 3; i会不会加到 INT_MAX - 2 为止?
        //leetcode 里当 n = INT_MAX - 3时确实程序就崩溃了。我日
        for (int i = 2; i < sqrt(n); ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++count;
            }
        }
        return count;
    }
};
