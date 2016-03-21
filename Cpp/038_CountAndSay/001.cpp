class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for (; n > 1; --n) {
            string next;
            for (int i = 0; i < current.size(); ++i) {
                int count = 1;
                while (i + 1 < current.size() && current[i] == current[i + 1]) {
                    ++count;
                    ++i;
                }
                next += to_string(count) + current[i];
            }
            current = move(next);
        }
        return current;
    }
};