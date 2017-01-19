class Solution {
public:
    int findKthNumber(int n, int k) {
        --k;
        int current = 1;
        while (k) {
            int step = cal_steps(n, current, current + 1);
            if (step <= k) {
                k -= step;
                ++current;
            } else {
                --k;
                current *= 10;
            }
        }
        return current;
    }
private:
    int cal_steps(int n, long long n1, long long n2) {
        int step = 0;
        while (n1 <= n) {
            //为什么n + 1而n2不加
            //因为n2是开区间
            //Numbers prefixed by result are the union of the following intervals:
            //[result, result+1)
            //[result*10, (result+1)*10 )
            //[result*100, (result+1)*100 )
            step += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return step;
    }
};