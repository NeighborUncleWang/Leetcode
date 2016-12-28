class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (string& word : sentence) {
            s += word + " "; 
        }
        //不需要s.pop_back()
        int size = s.size();
        vector<int> map(size, 0);
        for (int i = 1; i < size; ++i) {
            map[i] = s[i] == ' ' ? 1 : map[i - 1] - 1;
        }
        int start = 0;
        for (int i = 0; i < rows; ++ i) {
            start += cols;
            start += map[start % size];
        }
        return start / size;
    }
};