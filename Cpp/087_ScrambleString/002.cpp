class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if (s1 == s2) {
            return true;
        } else if (size1 != size2) {
            return false;
        }
        vector<int> count(256, 0);
        for (int i = 0; i < size1; ++i) {
            ++count[s1[i]];
            --count[s2[i]];
        }
        bool allZeroes = all_of(count.begin(), count.end(), [](int num) { return num == 0; });
        if (!allZeroes) {
            return false;
        }
        for (int i = 1; i < size1; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) 
            && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            } else if (isScramble(s1.substr(0, i), s2.substr(size2 - i))
            && isScramble(s1.substr(i), s2.substr(0, size2 - i))) {
                return true;
            }
        }
        return false;
    }
};