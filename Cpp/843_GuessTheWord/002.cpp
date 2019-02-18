/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        vector<vector<int>> histograms(n, vector<int>(n, 0));
        // we must check the histograms[i][i] entries to make it 6
        // otherwise we may add guess into possible
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int match = 0;
                for (int k = 0; k < 6; ++k) {
                    if (wordlist[i][k] == wordlist[j][k]) {
                        ++match;
                    }
                }
                histograms[i][j] = histograms[j][i] = match;
            }
        }
        // path contains words already gussed
        unordered_set<int> path;
        vector<int> possible(n);
        iota(possible.begin(), possible.end(), 0);
        for (int i = 0, match = 0; i < 10; ++i) {
            int guess = solve(path, possible, histograms);
            match = master.guess(wordlist[guess]);
            if (match == 6) return;
            vector<int> next;
            for (int num : possible) {
                // here we must check whether num == guess
                // if we didn't intialize histograms[i][i] entries
                // otherwise the histograms[i][i] is zero and guess may be added
                // to possible
                if (num == guess) continue;
                if (histograms[guess][num] == match) {
                    next.push_back(num);
                }
            }
            possible = move(next);
            path.insert(guess);
        }
    }
private:
    int solve(unordered_set<int>& path, vector<int>& possible, vector<vector<int>>& histograms) {
        if (possible.size() <= 2) return possible[0];
        int resSize = possible.size();
        int resGuess = -1;
        for (int guess : possible) {
            // acutally we don't need to check whether guess is in path or not
            // because possible will not contain guessed words
            // if (path.find(guess) == path.end()) {
                vector<int> groups(7, 0);
                for (int num : possible) {
                    if (num != guess) {
                        ++groups[histograms[num][guess]];
                    }
                }
                int maxHis = *max_element(groups.begin(), groups.end());
                // the maxHis is the largest amount of words with a specific
                // distance related to currently chosen guess word
                // it is also the size for the next candidates set in variable possible
                if (maxHis < resSize) {
                    resSize = maxHis;
                    resGuess = guess;
                }
            // }
        }
        return resGuess;
    }
};
