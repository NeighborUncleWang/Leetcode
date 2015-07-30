class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        int maxLength = max(v1.size(), v2.size());
        for (int i = 0; i < maxLength; ++i) {
            int number1 = i >= v1.size() ? 0 : stoi(v1[i]);
            int number2 = i >= v2.size() ? 0 : stoi(v2[i]);
            if (number1 > number2) {
                return 1;
            } else if (number1 < number2) {
                return - 1;
            }
        }
        return 0;
    }
private:
    vector<string> split(string& s) {
        stringstream ss(s);
        string temp;
        vector<string> result;
        while(getline(ss, temp, '.')) {
            result.push_back(temp);
        }
        return result;
    }
};
