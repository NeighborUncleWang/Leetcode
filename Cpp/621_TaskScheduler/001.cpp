class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char ch : tasks) {
            ++count[ch - 'A'];
        }
        sort(count.begin(), count.end());
        int max_val = count[25] - 1, idle_slots = n * max_val;
        for (int i = 24; i >= 0 && count[i] > 0; --i) {
            idle_slots -= min(count[i], max_val);
        }
        return idle_slots > 0 ? tasks.size() + idle_slots : tasks.size();
    }
};