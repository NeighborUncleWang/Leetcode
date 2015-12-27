class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int wordSize = word.size();
        for (int i = 0; i < (1 << wordSize); ++i) {
            result.push_back(parseWord(word, i));
        }
        return result;
    }
private:
    string parseWord(string& word, int mask) {
        string abbreviation;
        int count = 0;
        //there is only two options for each ch in word
        //add it to abbreviation or count it as a number
        //when mask % 2, it means count current char as a number
        for (char ch : word) {
            if (mask % 2) {
                ++count;
            } else {
                if (count) {
                    abbreviation += to_string(count);
                    count = 0;
                }
                abbreviation += ch;
            }
            mask >>= 1;
        }
        if (count) {
            abbreviation += to_string(count);
        }
        return abbreviation;
    }
};