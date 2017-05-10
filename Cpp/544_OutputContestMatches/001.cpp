class Solution {
public:
    string findContestMatch(int n) {
        vector<string> cur;
        for (int i = 1; i <= n; ++i) {
            cur.push_back(to_string(i));
        }
        while (cur.size() != 1) {
            vector<string> next;
            int size = cur.size();
            for (int i = 0; i < size / 2; ++i) {
                next.push_back("(" + cur[i] + "," + cur[size - 1 - i] + ")");
            }
            cur = move(next);
        }
        return cur[0];
    }
};