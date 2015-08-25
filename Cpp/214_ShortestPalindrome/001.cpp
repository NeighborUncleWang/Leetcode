class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int k = -1;
        //this algorithm will not work if s is already a palindrome
        //so we need to test the corner case, this can also work when s is empty
        //for instance, if s = aba, then pattern.back() will be 0, 
        //then the result will be ababa, but atcually aba is the shortest palidrome
        if (r == s) {
            return s;
        }
        //pattern[0] must be -1
        vector<int> pattern(r.size(), -1);
        for (int i = 1; i < r.size(); ++i) {
            //其实产生pattern矩阵的过程就是被搜索的pattern自己match自己的过程
            //所以下面的函数本质上还是借用了生成pattern矩阵的思想
            //虽然这里是两个不同函数进行比较
            while (k > - 1 && s[k + 1] != r[i]) {
                k = pattern[k];
            }
            if (s[k + 1] == r[i]) {
                ++k;
            }
            pattern[i] = k; 
        }
        //pattern.back() + 1 is the length of the proper suffix and proper prefix
        //pattern.back() is only the index of the proper prefix
        return r.substr(0, r.size() - pattern.back() - 1) + s;
    }
};
