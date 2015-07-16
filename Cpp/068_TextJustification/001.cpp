class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string solution;
        int count = 0;
        int last = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (count + words[i].size() + i - last > maxWidth) {
                int spaceNumber = 0;
                int extraSpace = 0;
                // test whether i - 1 - last is 0 before use it as divisor 
                if (i - 1 - last > 0) {
                    spaceNumber = (maxWidth - count) / (i - 1 - last);//contain words[i - 1]
                    extraSpace = (maxWidth - count) % (i - 1 - last);
                }
                for (int j = last; j < i; ++j) {
                    solution += words[j];
                    if (j < i - 1) {
                        solution.append(spaceNumber, ' ');
                        if (extraSpace) {
                            solution.append(1, ' ');
                            --extraSpace;
                        }
                    }
                }
                //考虑当前行只有一个单词，所以上面添加space的代码不会执行(因为i - 1 - last == 0), 所以要单独考虑，把空格一直加到行尾知道行长度达到maxWidth为止
                for (int i = solution.size(); i < maxWidth; ++i) {
                    solution.append(1, ' ');
                }
                result.push_back(solution);
                solution.clear();
                count = 0;
                last = i;
            }
            count += words[i].size();
        }
        for (int i = last; i < words.size(); ++i) {
            solution += words[i];
            if (i < words.size() - 1) {
                solution.append(1, ' ');
            }
        }
        for (int i = solution.size(); i < maxWidth; ++i) {
            solution.append(1, ' ');
        }
        result.push_back(solution);
        return result;
    }
};
