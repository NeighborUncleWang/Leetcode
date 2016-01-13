class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //since the char 'A', 'C', 'G', 'T' is different for their lowest 3 bits
        //so we use these 3 bits to encode these chars
        //By observing that s[i] & 7 is never 0, each of the first nine substrings 
        //with length < 10 will have unique hash key and will never collide with other 10-letter long sequences. 
        //Therefore the first loop could be removed and be compacted into a single loop.
        unordered_map<int, int> hashMap;
        vector<string> result;
        for (int i = 0, hashCode = 0; i < s.size(); ++i) {
            hashCode = (hashCode << 3 | (s[i] & 0x00000007)) & 0x3FFFFFFF;
            if (hashMap[hashCode]++ == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};