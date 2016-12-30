class Solution {
private:
    int AbbrLength(int sequence, int n) {
        int count = n;
        int bound = 1 << n;
        for (int mask = 3; mask < bound; mask <<= 1) {
            if ((sequence & mask) == 0) --count;
        }
        return count;
    }
    void dfs(vector<int>& sequences, int mask, int& min_length, int n, int& min_mask) {
        int length = AbbrLength(mask, n);
        if (length >= min_length) return;
        bool valid = true;
        for (int& sequence : sequences) {
            if ((mask & sequence) == 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            min_length = length;
            min_mask = mask;
        }
    }
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> sequences;
        for (string& s : dictionary) {
            if (s.size() == target.size()) {
                int sequence = 0;
                for (int i = 0; i < s.size(); ++i) {
                    if (s[i] != target[i]) {
                        sequence |= (1 << i);
                    }
                }
                sequences.push_back(sequence);
            }
        }
        int mask = 0, min_length = INT_MAX, n = target.size(), min_mask = 0;
        for (int i = 0; i < pow(2,n); ++i) {
            dfs(sequences, i, min_length, n, min_mask);
        }
        string result;
        for (int i = 0; i < n;) {
            if ((min_mask & (1 << i)) != 0) {
                result += target[i++];
            } else {
                int num = 0;
                while (i < n && ((min_mask & (1 << i)) == 0)) {
                    ++i;
                    ++num;
                }
                result += to_string(num);
            }
        }
        return result;
    }
};