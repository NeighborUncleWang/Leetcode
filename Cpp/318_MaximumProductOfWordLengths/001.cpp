class Solution {
public:
    int maxProduct(vector<string>& words) {
        int wordsSize = words.size();
        vector<int> mask(wordsSize, 0);
        //if we use unordered_map to store the mask
        //the space complexity becomes O(2^n)
        //someone claims this to be constant space
        for (int i = 0; i < wordsSize; ++i) {
            for (char ch : words[i]) {
                mask[i] |= 1 << (ch - 'a');
            }
        }
        int maxLength = 0;
        for (int i = 0; i < wordsSize; ++i) {
            for (int j = i + 1; j < wordsSize; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    maxLength = max(maxLength, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return maxLength;
    }
};