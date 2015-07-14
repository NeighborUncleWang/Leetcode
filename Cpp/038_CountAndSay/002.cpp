class Solution {
public:
    string countAndSay(int n) {
        string result;
        if (n == 0) {
            return result;
        }
        int stringIndex = 0;
        result.push_back('1');
        for (int i = 1; i < n; ++i) {
            int count = 0;
            char c = result[stringIndex];
            string temp;
            for ( ; stringIndex < result.size(); ++stringIndex) {
                ++count;
                if (stringIndex < result.size() - 1 && result[stringIndex + 1] != result[stringIndex]) {
                    temp.push_back(count + '0');
                    temp.push_back(c);
                    count = 0;
                    c = result[stringIndex + 1];
                }
            }
            temp.push_back(count + '0');
            temp.push_back(c);
            result += temp;
        }
        return result;
    }
};

