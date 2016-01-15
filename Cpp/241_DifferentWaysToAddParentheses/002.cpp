class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> hashMap;
        return TopDownMemoization(input, hashMap);
    }
private:
    vector<int> TopDownMemoization(string& input, unordered_map<string, vector<int>>& hashMap) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> resultLeft;
                vector<int> resultRight;
                string substr = input.substr(0, i);
                if (hashMap.find(substr) != hashMap.end()) {
                    resultLeft = hashMap[substr];
                } else {
                    resultLeft = TopDownMemoization(substr, hashMap);
                }
                substr = input.substr(i + 1);
                if (hashMap.find(substr) != hashMap.end()) {
                    resultRight = hashMap[substr];
                } else {
                    resultRight = TopDownMemoization(substr, hashMap);
                }
                for (int numLeft : resultLeft) {
                    for (int numRight : resultRight) {
                        int val;
                        if (input[i] == '+') {
                            val = numLeft + numRight;
                        } else if (input[i] == '-') {
                            val = numLeft - numRight;
                        } else {
                            val = numLeft * numRight;
                        }
                        result.push_back(val);
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        hashMap[input] = result;
        return result;
    }
};