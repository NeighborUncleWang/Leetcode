class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            string temp;
            //这里得假设result不为empty否则会出错
            //或者最开始把count初始化为0，j初始化为1
            //if (result[j] != result[j - 1])改成if (j > 0 && result[j] != result[j - 1])
            //但是和后面count设置为1会不太一致
            int count = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] != result[j - 1]) {
                    temp += to_string(count) + result[j - 1];
                    count = 1;
                } else {
                    ++count;
                }
            }
            temp += to_string(count) + result.back();
            result = move(temp);
        }
        return result;
    }
};