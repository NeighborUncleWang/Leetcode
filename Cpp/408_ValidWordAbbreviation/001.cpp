class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int size1 = word.size();
        int size2 = abbr.size();
        int i = 0, j = 0;
        for (; i < size1 && j < size2;) {
            if (word[i] == abbr[j]) {
                ++i;
                ++j;
            } else if (isdigit(abbr[j]) && abbr[j] != '0') {
                string num;
                while (j < size2 && isdigit(abbr[j])) {
                    num += abbr[j++];
                }
                i += stoi(num);
            } else {
                return false;
            }
        }
        return i == size1 && j == size2;
    }
};