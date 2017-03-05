class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int primesSize = primes.size();
        vector<int> indices(primesSize, 0);
        vector<int> ugly(n, 1);
        for (int i = 1; i < n; ++i) {
            int nextUgly = INT_MAX;
            for (int i = 0; i < primesSize; ++i) {
                nextUgly = min(nextUgly, primes[i] * ugly[indices[i]]);
            }
            ugly[i] = nextUgly;
            for (int i = 0; i < primesSize; ++i) {
                //所有只要和nextUgly相等的index都要+1
                //不是只加了一次就可以停了
                if (nextUgly == primes[i] * ugly[indices[i]]) {
                    ++indices[i];
                }
            }
        }
        return ugly.back();
    }
};