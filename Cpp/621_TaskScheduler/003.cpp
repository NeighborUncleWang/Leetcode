class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char ch : tasks) {
            ++count[ch - 'A'];
        }
        priority_queue<int, vector<int>, less<int>> pq;
        for (int num : count) {
            if (num > 0) {
                pq.push(num);
            }
        }
        int times = 0;
        vector<int> temp;
        while (!pq.empty()) {
            for (int i = 0; i <= n; ++i) {
                if (!pq.empty()) {
                    int cur = pq.top();
                    pq.pop();
                    if (--cur > 0) {
                        temp.push_back(cur);
                    }
                }
                ++times;
                if (pq.empty() && temp.empty()) {
                    return times;
                }
            }
            for (int l : temp) {
                pq.push(l);
            }
            temp.clear();
        }
        return times;
    }
};