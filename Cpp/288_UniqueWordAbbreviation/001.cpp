class ValidWordAbbr {
private:
    unordered_map<string, string> hashMap;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            string key = getKey(word);
            if (hashMap.find(key) != hashMap.end()) {
                if (hashMap[key] != word) {
                    hashMap[key] = "";
                }
            } else {
                hashMap[key] = word;
            }
        }
    }
    string getKey(const string& word) {
        //this function don't return the abbreviaton for the word
        //but the key has the same uniqueness as the abbreviation 
        int n = word.size();
        return word.front() + to_string(n) + word.back();
    }
    bool isUnique(string word) {
        string key = getKey(word);
        return hashMap.find(key) == hashMap.end() || hashMap[key] == word;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");