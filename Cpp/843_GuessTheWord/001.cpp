/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int matches(const string& left, const string& right) {
        int res = 0;
        for (int i = 0; i < 6; ++i) {
            if (left[i] == right[i]) {
                ++res;
            }
        }
        return res;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            int index = rand() % wordlist.size();
            x = master.guess(wordlist[index]);
            vector<string> temp;
            for (auto& word : wordlist) {
                /*We start by taking all words as potential candidates. If we guess a word,
                we're given its distance from the secret, which allows us to eliminate words
                whose distance from the guess is different. That is,
                if we know that the secret is 4 characters away from the guess,
                then we can eliminate all words whose distance from the guess is not 4,
                because they can't be the secret.*/
                if (matches(word, wordlist[index]) == x) {
                    temp.push_back(word);
                }
            }
            wordlist = move(temp);
        }
    }
};
