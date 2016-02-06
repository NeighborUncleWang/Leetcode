class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s.front() == '0') return 0;
        int r2 = 1;
        int r1 = 1;
        for (int i = 1; i < n; ++i) {
            int current = 0;
            if (s[i] != '0') {
                current += r1;
            }
            //这里假设输入s是valid，都是'0'~'9'
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                current += r2;
            }
            r2 = r1;
            r1 = current;
        }
        return r1;
    }
};