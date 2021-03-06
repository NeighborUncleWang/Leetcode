class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        //如果没有non-empty string的前提话需要check s1 和s2是否为empty
        int i = 0, j = 0, count1 = 0, count2 = 0;
        while (count1 < n1) {
            if (s1[i] == s2[j]) {
                ++j;
                if (j == s2.size()) {
                    j = 0;
                    ++count2;
                }
            }
            ++i;
            if (i == s1.size()) {
                i = 0;
                ++count1;
            }
        }
        return count2 / n2;
    }
};