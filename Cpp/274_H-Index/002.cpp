class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        vector<int> counts(n + 1, 0);
        //当0 <= i < n时,counts[i]存着cite数==i的paper数量
        //当i == n时,counts[i]存着cite数>=n的paper数量
        //这个解法和counting sort非常像
        //因为h-index <= n,
        //所以不用像counting sort那样开一个size为max_citation的数组
        for (int cites : citations) {
            if (cites > n) {
                ++counts[n];
            } else {
                ++counts[cites];
            }
        }
        for (int i = n; i > 0; --i) {
            h += counts[i];
            if (h >= i) {
                return i;
            }
        }
        return 0;
    }
};