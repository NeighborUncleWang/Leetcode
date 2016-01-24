class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string sequence;
        dfs(result, sequence, s, 0, 0);
        return result;
    }
private:
    void dfs(vector<string>& result, string sequence, string& s, int index, int section) {
        if (index == s.size() && section == 4) {
            result.push_back(sequence);
            return;
        } else if (index == s.size() || section == 4) {
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            string number = s.substr(index, i - index + 1);
            if (stoi(number) > 255 || number.size() > 1 && number[0] == '0') {
                break;
            }
            dfs(result, sequence + (section == 0 ? "" : ".") + number, s, i + 1, section + 1);
        }
    }
};