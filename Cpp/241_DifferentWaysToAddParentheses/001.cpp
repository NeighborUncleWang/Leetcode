class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if (input.size() == 0) {
            return result;
        }
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') {
                            result.push_back(left[j] + right[k]);
                        } else if (input[i] == '-') {
                            result.push_back(left[j] - right[k]);
                        } else {
                            result.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        return result;
    }
};
