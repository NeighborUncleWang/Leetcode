class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s.front() == '0') return 0;
        int previous2 = 1;
        //也可以前面不判断s.front() == '0'
        //在这里写int previous1 = s[0] == '0' ? 0 : 1;
        int previous1 = 1;
        for (int i = 1; i < n; ++i) {
            int current = 0;
            if (s[i] != '0') {
                current += previous1;
            }
            //这里假设输入s是valid，都是'0'~'9'
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                current += previous2;
            }
            previous2 = previous1;
            previous1 = current;
        }
        return previous1;
    }
};