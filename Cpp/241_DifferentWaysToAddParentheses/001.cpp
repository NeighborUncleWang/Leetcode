class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //其实diffWaysToCompute整个就是divide-conquer里的SplitMerge function
        //一般的divide-conquer比如Merge-Sort只有一种split方法(从中间一分为二)
        //这道题有多种split方法，所以最外面加了一个for loop
        //去掉for loop其实和一般SplitMerge一样
        vector<int> result;
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