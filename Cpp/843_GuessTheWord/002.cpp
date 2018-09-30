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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int match = 0;
                for (int k = 0; k < 6; ++k) {
                    if (wordlist[i][k] == wordlist[j][k]) {
                        ++match;
                    }
                }
                histograms[i][j] = histograms[j][i] = match;
            }
        }
        unordered_set<int> path;
        vector<int> possible(n);
        iota(possible.begin(), possible.end(), 0);
        for (int i = 0, match = 0; i < 10; ++i) {
            int guess = solve(path, possible, histograms);
            match = master.guess(wordlist[guess]);
            if (match == 6) return;
            vector<int> next;
            for (int num : possible) {
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
            if (path.find(guess) == path.end()) {
                vector<int> groups(7, 0);
                for (int num : possible) {
                    if (num != guess) {
                        ++groups[histograms[num][guess]];
                    }
                }
                int maxHis = *max_element(groups.begin(), groups.end());
                if (maxHis < resSize) {
                    resSize = maxHis;
                    resGuess = guess;
                }
            }
        }
        return resGuess;
    }
};
