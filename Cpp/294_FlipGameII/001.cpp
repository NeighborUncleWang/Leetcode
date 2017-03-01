class Solution {
public:
    bool canWin(string s) {
        unordered_map<string, bool> cache;
        return helper(s, cache);
    }
private:
    bool helper(string s, unordered_map<string, bool>& cache) {
        if (cache.find(s) != cache.end()) {
            return cache[s];
        }
        for (auto it = s.find("++", 0); it != string::npos; it = s.find("++", it + 1)) {
            if (!helper(s.substr(0, it) + "--" + s.substr(it + 2), cache)) {
                cache[s] = true;
                return cache[s];
            }
        }
        cache[s] = false;
        return cache[s];
    }
};