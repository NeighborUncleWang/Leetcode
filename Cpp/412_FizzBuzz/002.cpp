class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1, fizz = 3, buzz = 5; i <= n; ++i) {
            if (i == fizz && i == buzz) {
                result.push_back("FizzBuzz");
                fizz += 3;
                buzz += 5;
            } else if (i == fizz) {
                result.push_back("Fizz");
                fizz += 3;
            } else if (i == buzz) {
                result.push_back("Buzz");
                buzz += 5;
            } else {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};