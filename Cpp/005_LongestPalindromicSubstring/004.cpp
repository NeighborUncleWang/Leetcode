class Solution {
public:
    string longestPalindrome(string s) {
        string temp = preprocess(s);
        int n = temp.size();
        int maxRightId = 0;
        int maxRight = 0;
        vector<int> p(n, 0);
        int centralIndex = 0;
        int maxRadius = 0;
        for (int i = 0; i < n; ++i) {
            int iMirror = 2 * maxRightId - i;
            if (i <= maxRight) {
                p[i] = min(p[iMirror], maxRight - i);
            } else {
                p[i] = 0;
            }
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n
                   && temp[i - p[i] - 1] == temp[i + p[i] + 1]) {
                ++p[i];
            }
            if (i + p[i] > maxRight) {
                maxRightId = i;
                maxRight = i + p[i];
            }
            if (p[i] > maxRadius) {
                centralIndex = i;
                maxRadius = p[i];
            }
        }
        return s.substr((centralIndex - maxRadius) / 2, maxRadius);
    }
private:
    string preprocess(string& s) {
        if (s.size() == 0) {
            return s;
        }
        string result = "#";
        for (auto &i : s) {
            result += i;
            result += '#';
        }
        //最前面没有加'^',最后面没有加'$'
        //因为即使加了如果原字符串里面有'^'或者'$'
        //line18和line19还是会上溢或者下溢
        //所以还是得判断p[i]是否出界
        //具体看http://www.felix021.com/blog/read.php?2040的讨论
        return result;
    }
};

