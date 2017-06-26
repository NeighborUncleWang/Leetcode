class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char ch : tasks) {
            ++count[ch - 'A'];
        }
        sort(count.begin(), count.end());
        int i = 24;
        while (i >= 0 && count[i] == count[25]) --i;
        return max((int)tasks.size(), (count[25] - 1) * (n + 1) + 25 - i);
    }
};