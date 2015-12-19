class ValidWordAbbr {
private:
    vector<string> dictionary;
public:
    ValidWordAbbr(vector<string> &dictionary) : dictionary(dictionary) {
    }

    bool isUnique(string word) {
        string currentWord;
        for (int i = 0; i < dictionary.size(); ++i) {
            currentWord = dictionary[i];
            if (currentWord.size() == word.size() && currentWord.front() == word.front()
            && currentWord.back() == word.back() && word != currentWord) {
                return false;
            }
        }
        return true;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");