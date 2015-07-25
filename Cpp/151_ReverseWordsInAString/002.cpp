class Solution {
public:
    void reverseWords(string &s) {
        auto start = s.find_first_not_of(' ');
        auto end = s.find_last_not_of(' ');
        if (string::npos == start || string::npos == end) {
            s.clear();
            return;
        }
        s = s.substr(start, end - start + 1);
        int index = 0;
        int n = s.size();
		//delete the extra spaces between words
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' || i < s.size() - 1 && s[i] == ' ' && s[i + 1] != ' ') {
                s[index] = s[i];
                ++index;
            } else {
                --n;
            }
        }
        s.resize(n);
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            while (right < s.size() && s[right] != ' ') {
                ++right;
            }
            int next = right + 1;
            --right;
            //remembet the reverse function reverses [begin, end), so right need to add + 1
            reverse(s.begin() + left, s.begin() + right + 1);
            left = next;
            right = next;
        }
        return;
    }
};
