class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int size = words.size();
        for (int i = 0, l, k; i < size; i += k) {
            for (l = 0, k = 0; i + k < size && l + words[i + k].size() <= maxWidth - k; ++k) {
                l += words[i + k].size();
            }
            string temp = words[i];
            //这里j还是相当于index
            //和reference里稍微有点不一样
            for (int j = 1; j < k; ++j) {
                if (i + k >= size) {
                    temp += ' ';
                } else {
                    temp.append((maxWidth - l) / (k - 1) + (j <= (maxWidth - l) % (k - 1) ? 1 : 0), ' ');
                }
                temp += words[i + j];
            }
            //不一定是最后一行才执行这行code
            //如果某行只能放下一个word，也会执行这行code把剩下的空间用空格补齐
            temp.append(maxWidth - temp.size(), ' ');
            result.push_back(move(temp));
        }
        return result;
    }
};