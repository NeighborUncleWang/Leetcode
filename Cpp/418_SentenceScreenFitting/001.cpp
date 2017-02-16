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
        //map记录的是需要对start位置做出的修正值
        //如果当前位置是空格说明previous row最后一个word没有加空格
        //因为每个row不可能以空格开头，所以可以跳过
        //如果当前位置不是空格，则记录需要减去多少值才能达到上一个空格的位置
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