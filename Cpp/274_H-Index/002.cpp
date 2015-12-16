class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        vector<int> counts(n + 1, 0);
        for (int cites : citations) {
            ++counts[min(n, cites)];
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