class Solution {
public:
    string rearrangeString(string str, int k) {
        vector<int> count(26, 0), valid(26, 0);
        for (char ch : str) {
            ++count[ch - 'a'];
        }
        string result;
        for (int i = 0; i < str.size(); ++i) {
            int index = FindValidMax(count, valid, i);
            if (index == -1) return "";
            --count[index];
            valid[index] = i + k;
            result += 'a' + index;
        }
        return result;
    }
private:
    int FindValidMax(vector<int>& count, vector<int>& valid, int index) {
        int max_count = 0;
        int result = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > max_count && valid[i] <= index) {
                result = i;
                max_count = count[i];
            }
        }
        return result;
    }
};