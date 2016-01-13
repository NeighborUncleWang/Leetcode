class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        //if we use unordered_map to store the mask
        //the space complexity becomes O(2^n)
        //someone claims this to be constant space
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            for (char ch : words[i]) {
                mask[i] |= 1 << (ch - 'a');
            }
            for (int j = 0; j < i; ++j) {
                //&优先级比==低
                if ((mask[i] & mask[j]) == 0) {
                    maxLength = max(maxLength, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxLength;
    }
};